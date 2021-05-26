#include "base_funcs.h"
#include <Arduino.h>

//implement data averaging ??
int get_dist_l() {
  int dist;
  digitalWrite(EMIT_L_PIN, HIGH);
  delay(EMITTER_ON_TIME);
  dist = analogRead(RECIVER_L_PIN);
  digitalWrite(EMIT_L_PIN, LOW);
  return dist;
}

int get_dist_r() {
  int dist;
  digitalWrite(EMIT_R_PIN, HIGH);
  delay(EMITTER_ON_TIME);
  dist = analogRead(RECIVER_R_PIN);
  digitalWrite(EMIT_R_PIN, LOW);
  return dist;
}

int get_dist_fr() {
  int dist;
  digitalWrite(EMIT_FR_PIN, HIGH);
  delay(EMITTER_ON_TIME);
  dist = analogRead(RECIVER_FR_PIN);
  digitalWrite(EMIT_FR_PIN, LOW);
  return dist;
}

int get_dist_fl() {
  int dist;
  digitalWrite(EMIT_FL_PIN, HIGH);
  delay(EMITTER_ON_TIME);
  dist = analogRead(RECIVER_FL_PIN);
  digitalWrite(EMIT_FL_PIN, LOW);
  return dist;
}

void turn_all_emit_on() {
  digitalWrite(EMIT_FL_PIN, HIGH);
  digitalWrite(EMIT_FR_PIN, HIGH);
  digitalWrite(EMIT_R_PIN, HIGH);
  digitalWrite(EMIT_L_PIN, HIGH);
}

void turn_all_emit_off() {
  digitalWrite(EMIT_FL_PIN, LOW);
  digitalWrite(EMIT_FR_PIN, LOW);
  digitalWrite(EMIT_R_PIN, LOW);
  digitalWrite(EMIT_L_PIN, LOW);
}

void turn_all_led_on() {
  digitalWrite(LED1_PIN, HIGH);
  digitalWrite(LED2_PIN, HIGH);
  digitalWrite(LED3_PIN, HIGH);
}


void turn_all_led_off() {
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
  digitalWrite(LED3_PIN, LOW);
}


void set_motor_l(int dir, int mspeed) {
  if (dir == 0) {
    digitalWrite(M2_FWD_PIN, LOW);
    digitalWrite(M2_BACK_PIN, HIGH);
    analogWrite(M2_SPD_PIN, mspeed);
  }
  else if (dir == 1) {
    digitalWrite(M2_FWD_PIN, HIGH);
    digitalWrite(M2_BACK_PIN, LOW);
    analogWrite(M2_SPD_PIN, mspeed);
  }
  else if (dir == 2) {
    digitalWrite(M2_FWD_PIN, LOW);
    digitalWrite(M2_BACK_PIN, LOW);
    analogWrite(M2_SPD_PIN, 0);
  }
  else {
    //incorrect direction given
  }
}

void set_motor_r(int dir, int mspeed) {
  if (dir == 0) {

    digitalWrite(M1_BACK_PIN, LOW);
    digitalWrite(M1_FWD_PIN, HIGH);
    analogWrite(M1_SPD_PIN, mspeed);
  }
  else if (dir == 1) {
    digitalWrite(M1_FWD_PIN, LOW);
    digitalWrite(M1_BACK_PIN, HIGH);
    analogWrite(M1_SPD_PIN, mspeed);
  }
  else if (dir == 2) {
    analogWrite(M1_SPD_PIN, 0);
    digitalWrite(M1_FWD_PIN, LOW);
    digitalWrite(M1_BACK_PIN, LOW);

  }
  else {
    //incorrect direction given
  }
}


void set_buzzer_on(int freq) {
  tone(BUZZ_PIN, freq);
  //analogWrite(BUZZ_PIN, 2);
  //draws about 0.8ma
  //foroums say limit teensy pins to 1-4ma
}

void set_buzzer_off() {
  tone(BUZZ_PIN, 0);
}

void bt_write(String s) {
  Serial7.println(s);
}

int read_sw_1() {
  return digitalRead(SW_1_PIN);
}

int read_sw_2() {
  return digitalRead(SW_2_PIN);
}

int read_battery() {
  return analogRead(VOL_METER);
}

void red_led_on() {
  digitalWrite(LED3_PIN, HIGH);
}

void red_led_off() {
  digitalWrite(LED3_PIN, LOW);
}

void green_led_on() {
  digitalWrite(LED2_PIN, HIGH);
}

void green_led_off() {
  digitalWrite(LED2_PIN, LOW);
}

void yellow_led_on() {
  digitalWrite(LED1_PIN, HIGH);
}

void yellow_led_off() {
  digitalWrite(LED1_PIN, LOW);
}
