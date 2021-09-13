#pragma once
#define EMITTER_ON_TIME 2

#define EMIT_L_PIN 21 //D1
#define EMIT_R_PIN 18//D3
#define EMIT_FL_PIN 22 //D0
#define EMIT_FR_PIN 15 //D2

#define RECIVER_L_PIN 20 //Q1
#define RECIVER_R_PIN 19 //Q3
#define RECIVER_FL_PIN 23 //Q0
#define RECIVER_FR_PIN 14 //Q2

//static calibration ints
//constant detect wall threshold:
int dist_l();
int dist_r();
int dist_fr();
int dist_fl();

bool dist_front_open();
bool dist_left_open();
bool dist_right_open();
// int dist_l();
// int dist_r();
// int dist_fr();
// int dist_fl();

// bool dist_front_open();
// bool dist_left_open();
// bool dist_right_open();
