#pragma once
#define MOTOR_MAX TODO:
#define MOTOR_MIN TODO:

typedef enum Direction {
    FORWARD,
    BACKWARD,
    STOP
} Direction;

void set_motor_l(Direction dir, int speed);
void set_motor_r(Direction dir, int speed);

//make sure to implement rnage checking for values