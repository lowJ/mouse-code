#include <Arduino.h>
#include <motor_control.hpp>
void set_motor_r(Direction dir, float speed) {
    if (dir == FORWARD) {
        digitalWrite(M2_FWD_PIN, LOW);
        digitalWrite(M2_BACK_PIN, HIGH);
        analogWrite(M2_SPD_PIN, speed);
    } else if (dir == BACKWARD) {
        digitalWrite(M2_FWD_PIN, HIGH);
        digitalWrite(M2_BACK_PIN, LOW);
        analogWrite(M2_SPD_PIN, speed);
    } else if (dir == STOP) {
        digitalWrite(M2_FWD_PIN, LOW);
        digitalWrite(M2_BACK_PIN, LOW);
        analogWrite(M2_SPD_PIN, 0);
    } else {
        //incorrect direction given
    }
}

void set_motor_l(Direction dir, float speed) {
    if (dir == FORWARD) {
        digitalWrite(M1_BACK_PIN, LOW);
        digitalWrite(M1_FWD_PIN, HIGH);
        analogWrite(M1_SPD_PIN, speed);
    } else if (dir == BACKWARD) {
        digitalWrite(M1_FWD_PIN, LOW);
        digitalWrite(M1_BACK_PIN, HIGH);
        analogWrite(M1_SPD_PIN, speed);
    } else if (dir == STOP) {
        analogWrite(M1_SPD_PIN, 0);
        digitalWrite(M1_FWD_PIN, LOW);
        digitalWrite(M1_BACK_PIN, LOW);
    } else {
        //incorrect direction given
    } 
}