#pragma once
#define MOTOR_MAX TODO:
#define MOTOR_MIN TODO:

#define M1_BACK_PIN 8
#define M1_FWD_PIN 11
#define M1_SPD_PIN 12
#define M1_ENC_A_PIN 17
#define M1_ENC_B_PIN 16

#define M2_BACK_PIN 9
#define M2_FWD_PIN 7
#define M2_SPD_PIN 6
#define M2_ENC_A_PIN 1
#define M2_ENC_B_PIN 0

typedef enum Direction {
    FORWARD,
    BACKWARD,
    STOP
} Direction;

void set_motor_l(Direction dir, int speed);
void set_motor_r(Direction dir, int speed);

//make sure to implement rnage checking for values