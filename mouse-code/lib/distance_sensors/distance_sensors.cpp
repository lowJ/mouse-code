#include <Arduino.h>
#include <distance_sensors.hpp>
int dist_l() {
  int dist;
  digitalWrite(EMIT_L_PIN, HIGH);
  delay(EMITTER_ON_TIME);
  dist = analogRead(RECIVER_L_PIN);
  digitalWrite(EMIT_L_PIN, LOW);
  return dist;
}

int dist_r() {
  int dist;
  digitalWrite(EMIT_R_PIN, HIGH);
  delay(EMITTER_ON_TIME);
  dist = analogRead(RECIVER_R_PIN);
  digitalWrite(EMIT_R_PIN, LOW);
  return dist;
}

int dist_fr() {
  int dist;
  digitalWrite(EMIT_FR_PIN, HIGH);
  delay(EMITTER_ON_TIME);
  dist = analogRead(RECIVER_FR_PIN);
  digitalWrite(EMIT_FR_PIN, LOW);
  return dist;
}

int dist_fl() {
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

void dist_print_values() {
    Serial.print("FL: ");
    Serial.println(dist_fl());
    Serial.print("FR: ");
    Serial.println(dist_fr());
    Serial.print("L: ");
    Serial.println(dist_l());
    Serial.print("R: ");
    Serial.println(dist_r());
}