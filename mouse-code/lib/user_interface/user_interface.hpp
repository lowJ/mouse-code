#pragma once

#define BUZZ_PIN 2
#define SW_1_PIN 13

#define LED1_PIN 5
#define LED2_PIN 3
#define LED3_PIN 4
#define SW_2_PIN 10
#define VOL_METER 26//originally hooked up to 30, but 30 not an analog pin, so handwired to 26

#define HC05_RX 29
#define HC05_TX 28

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