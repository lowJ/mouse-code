#include <Arduino.h>
#include <user_interface.hpp>

void set_buzzer_on(int freq) {
    pinMode(BUZZ_PIN, OUTPUT);
  tone(BUZZ_PIN, freq);
  //analogWrite(BUZZ_PIN, 2);
  //draws about 0.8ma
  //foroums say limit teensy pins to 1-4ma
}

void set_buzzer_off() {
     pinMode(BUZZ_PIN, INPUT);
    //tone(BUZZ_PIN,1);
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