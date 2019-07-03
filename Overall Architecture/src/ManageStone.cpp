#include "Arduino.h"
#include "ManageStone.h"
#include "Constants.h"

ManageStone::ManageStone(){
  bool& _direction = direction; 
  int stoneNumber = 0; 
  bool lastEncoderState; 
  bool encoderState;
  int clawHeight =0;
  Servo armServo;
  Servo clawServo;
  Servo gauntletServo;
}

void ManageStone::collectStone(){
  turnClaw();
  moveArmToPillar();
  raiseClaw();
  clawServo.write(180); //deploy claw to get stone 
  stoneNumber++;
}
void ManageStone::dropInStorage(){
  moveArmToCentre();
  armServo.write(90);
  lowerClaw();
  switch(stoneNumber){
    case 1: 
      armServo.write(20);
      break;
    case 2:
      armServo.write(40);
      break;
    case 3:
      armServo.write(60);
      break;
    case 4: 
      armServo.write(120);
      break;
    case 5: 
      armServo.write(140);
      break;
    case 6: 
      armServo.write(160);
      break;
  } 
  clawServo.write(0); //open claw
  armServo.write(90); //return to default position 
} 
void ManageStone::dropInGauntlet(){

}

void ManageStone::moveArmToPillar(){
  do{
    if(direction){
      pwm_start(ARM_MOTOR_LEFT, CLOCK_FQ, MAX_SPEED, MAX_SPEED, 0); 
    }    
    else{
      pwm_start(ARM_MOTOR_RIGHT, CLOCK_FQ,MAX_SPEED, MAX_SPEED, 0); 
    }
  }
  while(analogRead(ARM_SONAR)!=PILLAR_DISTANCE);
  pwm_start(ARM_MOTOR_LEFT, CLOCK_FQ, MAX_SPEED, 0, 0);
  pwm_start(ARM_MOTOR_RIGHT, CLOCK_FQ, MAX_SPEED, 0, 0);
}

void ManageStone::moveArmToCentre(){
  do{
    if(direction){
      pwm_start(ARM_MOTOR_RIGHT, CLOCK_FQ, MAX_SPEED, MAX_SPEED, 0); 
    }    
    else{
      pwm_start(ARM_MOTOR_LEFT, CLOCK_FQ,MAX_SPEED, MAX_SPEED, 0); 
    }
  }
  while(digitalRead(ARM_HOME_SWITCH)==0); //how does the switch work, is it digital 0/1 input?
  pwm_start(ARM_MOTOR_LEFT, CLOCK_FQ, MAX_SPEED, 0, 0);
  pwm_start(ARM_MOTOR_RIGHT, CLOCK_FQ, MAX_SPEED, 0, 0);
}

void ManageStone::turnClaw(){
  if(direction){
    armServo.write(0); //0 degrees corresponds to left side
  }
  else{
    armServo.write(180);
  }
}

void ManageStone::raiseClaw(){
  clawHeight=0; // claw rests at default height  
  lastEncoderState = digitalRead(CLAW_ENCODER);
  do{
    encoderState = digitalRead(CLAW_ENCODER);
    if(encoderState != lastEncoderState){
      clawHeight++;
      lastEncoderState = encoderState;
    }
    pwm_start(CLAW_MOTOR_UP, CLOCK_FQ, MAX_SPEED, MAX_SPEED, 0); //raising claw
    //if there is a delay in stopping, then we dont need to go extra x distance using rotary encoder 
    //if there is no delay in stopping, ie. it stops exactly when the sonar reading jumps, 
    //use rotary encoder to move up a bit more.
  }
  while(analogRead(PILLAR_DISTANCE)<=PILLAR_DISTANCE+1);
}

void ManageStone::lowerClaw(){
  lastEncoderState = digitalRead(CLAW_ENCODER);
  encoderState = digitalRead(CLAW_ENCODER);
  do{
    if(encoderState != lastEncoderState){
      clawHeight--;
      lastEncoderState = encoderState;
    }
    pwm_start(CLAW_MOTOR_DOWN, CLOCK_FQ, MAX_SPEED, MAX_SPEED, 0);
  }
  while(clawHeight!=0);
  pwm_start(CLAW_MOTOR_DOWN, CLOCK_FQ, MAX_SPEED, 0, 0);
}

//use interrupts or find better way to count height for raiseClaw() and lowerClaw() since rn 
//with just a counter, it could miss counts if the motor is too fast 

