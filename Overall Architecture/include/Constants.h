#ifndef Constants_h
#define Constants_h

#define LEFT false
#define RIGHT true

#define SPLIT false
#define TAB true 

#define SMALL false 
#define LARGE true

#define METHANOS false 
#define THANOS true 

#define BACKWARDS false
#define FORWARDS true

#define TAB true
#define SPLIT false

//pwm_start
#define MAX_SPEED 1024 
#define CLOCK_FQ 100000 

//pins
#define MULTIPLEX_A PB12 
#define MULTIPLEX_B PB13
#define DEMULTIPLEX_ARM_H PB14 
#define DEMULTIPLEX_ARM_V PB15
#define DEMULTIPLEX_R_WHEEL PB5
#define DEMULTIPLEX_L_WHEEL PB4

#define ARM_SERVO PA7
#define CLAW_SERVO PB0
#define GAUNTLET_SERVO PB1

#define ARM_TOP_BOTTOM_LIMIT PA11
#define ARM_SIDES_LIMIT PA12
#define COLLISION PA15
#define TUNING_BUTTON PB3

#define LEFT_WHEEL PB_8
#define RIGHT_WHEEL PB_9

#define ARM_MOTOR_H PA_8
#define ARM_MOTOR_V PA_10

#define R_ALIGN PA_5
#define R_DECIDE PA_4
#define R_TAPE_FOLLOW PA_3
#define L_TAPE_FOLLOW PA_2
#define L_DECIDE PA_1
#define L_ALIGN PA_0

#define T_OR_M PA13 //switch, HIGH = THANOS

// ManageStone library
#define THREE_INCHES 3000 //ms since 1 in/s

// TapeFollower library
#define SPEED_TUNING 1.8
#define TURN_DELAY_TIME 200 
#define TURN_IN_PLACE_DELAY_TIME 400 // to ensure 180 degree turn 
#define DEBOUNCE 1000 // once junction detected, must be DEBOUNCE loops before next one 
#define ANGLE_START 70 
#define ANGLE_FINISH 140
#define START_DETECTION 30000 //number of loops to run before starting junction detection 
#define TOP_PATH_SIZE 4
#define BOTTOM_PATH_SIZE 6

#define _KP_WHEEL 162
#define _KD_WHEEL 12
#define _THRESHOLD 200
#define _DECIDE_THRESHOLD 300
#define _ALIGN_THRESHOLD 400

#endif

