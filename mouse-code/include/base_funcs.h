#ifndef base_funcs_h
#define base_funcs_h

#include <Arduino.h>
#define EMITTER_ON_TIME 2

#define EMIT_L_PIN 21 //D1
#define EMIT_R_PIN 18//D3
#define EMIT_FL_PIN 22 //D0
#define EMIT_FR_PIN 15 //D2

#define RECIVER_L_PIN 20 //Q1
#define RECIVER_R_PIN 19 //Q3
#define RECIVER_FL_PIN 23 //Q0
#define RECIVER_FR_PIN 14 //Q2

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

#define BUZZ_PIN 2
#define SW_1_PIN 13

#define LED1_PIN 5
#define LED2_PIN 3
#define LED3_PIN 4
#define SW_2_PIN 10
#define VOL_METER 26//originally hooked up to 30, but 30 not an analog pin, so handwired to 26

#define HC05_RX 29
#define HC05_TX 28


int get_dist_l();
int get_dist_r();
int get_dist_fr();
int get_dist_fl();


void turn_all_emit_on();
void turn_all_emit_off();

void turn_all_led_on();
void turn_all_led_off();

void set_motor_l(int dir, int mspeed);
void set_motor_r(int dir, int mspeed);

void set_buzzer_on(int freq);
void set_buzzer_off();
void bt_write(String s);
int read_sw_1();
int read_sw_2();
int read_battery();


void red_led_on();
void red_led_off();
void green_led_on();
void green_led_off();
void yellow_led_on();
void yellow_led_off();

#endif