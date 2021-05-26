#include <Arduino.h>

#define EMITTER_ON_TIME 1

#define EMIT_L_PIN 20 //D1
#define EMIT_R_PIN 17 //D3
#define EMIT_FL_PIN 22 //D0
#define EMIT_FR_PIN 15 //D2

#define RECIVER_L_PIN 21 //Q1
#define RECIVER_R_PIN 16 //Q3
#define RECIVER_FL_PIN 23 //Q0
#define RECIVER_FR_PIN 14 //Q2

#define WALL_L_THRESHOLD 00
#define WALL_R_THRESHOLD 00 //figure out these

#define M1_BACK_PIN 0
#define M1_FWD_PIN 1
#define M1_SPD_PIN 4
#define M1_ENC_A_PIN 8
#define M1_ENC_B_PIN 9

#define M2_BACK_PIN 3
#define M2_FWD_PIN 2
#define M2_SPD_PIN 5
#define M2_ENC_A_PIN 7
#define M2_ENC_B_PIN 6

int enc_a_l_count = 0;
int enc_b_l_count = 0;
int enc_a_r_count = 0;
int enc_b_r_count = 0;

#define BUZZ_PIN 13
#define SW_1_PIN 11
#define SW_2_PIN 12
#define RGB_DATA_PIN 10

enum Direction{
  FORWARDS = 0, BACKWARDS = 1, STOP = 2
};

void enc_a_l_intr_handler(){
  enc_a_l_count++;
}

void enc_b_l_intr_handler(){
  enc_b_l_count++;
}

void enc_a_r_intr_handler(){
  enc_a_r_count++;
}

void enc_b_r_intr_handler(){
  enc_b_r_count++;
}


void setup() {
  pinMode(EMIT_L_PIN, OUTPUT);
  pinMode(EMIT_R_PIN, OUTPUT);
  pinMode(EMIT_FL_PIN, OUTPUT);
  pinMode(EMIT_FR_PIN,OUTPUT);

  pinMode(RECIVER_L_PIN, INPUT);
  pinMode(RECIVER_R_PIN, INPUT);
  pinMode(RECIVER_FL_PIN, INPUT);
  pinMode(RECIVER_FR_PIN, INPUT);

  pinMode(M1_BACK_PIN, OUTPUT);
  pinMode(M1_FWD_PIN, OUTPUT);
  pinMode(M1_SPD_PIN, OUTPUT);
  pinMode(M1_ENC_A_PIN, INPUT); //check if input pullup
  pinMode(M1_ENC_B_PIN, INPUT);

  pinMode(M2_BACK_PIN, OUTPUT);
  pinMode(M2_FWD_PIN, OUTPUT);
  pinMode(M2_SPD_PIN, OUTPUT);
  pinMode(M2_ENC_A_PIN, INPUT); //check if input pullup
  pinMode(M2_ENC_B_PIN, INPUT);

  pinMode(BUZZ_PIN, OUTPUT);
  pinMode(SW_1_PIN, INPUT);
  pinMode(SW_2_PIN, INPUT);
  //pinMode(RGB_DATA_PIN, OUTPUT);

  //Interrupts
  attachInterrupt(M2_ENC_A_PIN, enc_a_l_intr_handler, RISING); //check if rising or falling
  attachInterrupt(M2_ENC_B_PIN, enc_b_l_intr_handler, RISING);
  attachInterrupt(M1_ENC_A_PIN, enc_a_r_intr_handler, RISING);
  attachInterrupt(M1_ENC_B_PIN, enc_b_r_intr_handler, RISING);
}


//implement data averaging ??
int get_dist_l(){
  int dist;
  digitalWrite(EMIT_L_PIN, HIGH);
  delay(EMITTER_ON_TIME);
  dist = analogRead(RECIVER_L_PIN);
  digitalWrite(EMIT_L_PIN, LOW);
  return dist;
}

int get_dist_r(){
  int dist;
  digitalWrite(EMIT_R_PIN, HIGH);
  delay(EMITTER_ON_TIME);
  dist = analogRead(RECIVER_R_PIN);
  digitalWrite(EMIT_R_PIN, LOW);
  return dist;
}

int get_dist_fr(){
  int dist;
  digitalWrite(EMIT_FR_PIN, HIGH);
  delay(EMITTER_ON_TIME);
  dist = analogRead(RECIVER_FR_PIN);
  digitalWrite(EMIT_FR_PIN, LOW);
  return dist;
}

int get_dist_fl(){
  int dist;
  digitalWrite(EMIT_FL_PIN, HIGH);
  delay(EMITTER_ON_TIME);
  dist = analogRead(RECIVER_FL_PIN);
  digitalWrite(EMIT_FL_PIN, LOW);
  return dist;
}

bool has_wall_l(){
  int dist = get_dist_l();
  if(dist <= WALL_L_THRESHOLD){
    return true;
  }
  else{
    return false;
  }
}

bool has_wall_r(){
  int dist = get_dist_r();
  if(dist <= WALL_R_THRESHOLD){
    return true;
  }
  else{
    return false;
  }
}


void set_motor_l(Direction dir, int speed){
  if(dir == 0){ //FWD
    digitalWrite(M2_FWD_PIN, );
    digitalWrite(M2_BACK_PIN, );
    digitalWrite(M2_SPD_PIN, );
  }
  else if(dir == 1){ //BACK
    digitalWrite(M2_FWD_PIN, );
    digitalWrite(M2_BACK_PIN, );
    digitalWrite(M2_SPD_PIN, );
  }
  else if(dir == 2){ //STOP
    digitalWrite(M2_FWD_PIN, );
    digitalWrite(M2_BACK_PIN, );
    digitalWrite(M2_SPD_PIN, );
  }
  else{
    //invalid direction given
  }
}

void set_motor_r(Direction dir, int speed){
  if(dir == 0){ //FWD
    digitalWrite(M1_FWD_PIN, );
    digitalWrite(M1_BACK_PIN, );
    digitalWrite(M1_SPD_PIN, );
  }
  else if(dir == 1){ //BACK
    digitalWrite(M1_FWD_PIN, );
    digitalWrite(M1_BACK_PIN, );
    digitalWrite(M1_SPD_PIN, );
  }
  else if(dir == 2){ //STOP
    digitalWrite(M1_FWD_PIN, );
    digitalWrite(M1_BACK_PIN, );
    digitalWrite(M1_SPD_PIN, );
  }
  else{
    //invalid direction given
  }
}

void rst_enc_a_l_count(){
  enc_a_l_count = 0;
}

void rst_enc_b_l_count(){
  enc_b_l_count = 0;
}

void rst_enc_a_r_count(){
  enc_a_r_count = 0;
}

void rst_enc_b_r_count(){
  enc_a_l_count = 0;
}




void loop() {
  // put your main code here, to run repeatedly:
}