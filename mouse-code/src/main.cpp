#include <Arduino.h>
#include "base_funcs.h"

int enc_a_l_count = 0;
int enc_b_l_count = 0;
int enc_a_r_count = 0;
int enc_b_r_count = 0;


// enum Direction{
//   FORWARDS = 0, BACKWARDS = 1, STOP = 2
// };

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
  Serial.begin(9600);             //USB serial
  Serial7.begin(9600);            //Bluetooth module
  pinMode(EMIT_L_PIN, OUTPUT);
  pinMode(EMIT_R_PIN, OUTPUT);
  pinMode(EMIT_FL_PIN, OUTPUT);
  pinMode(EMIT_FR_PIN, OUTPUT);

  pinMode(RECIVER_L_PIN, INPUT);
  pinMode(RECIVER_R_PIN, INPUT);
  pinMode(RECIVER_FL_PIN, INPUT);
  pinMode(RECIVER_FR_PIN, INPUT);

  pinMode(M1_BACK_PIN, OUTPUT);
  pinMode(M1_FWD_PIN, OUTPUT);
  pinMode(M1_SPD_PIN, OUTPUT);
  pinMode(M1_ENC_A_PIN, INPUT);     //check if input pullup
  pinMode(M1_ENC_B_PIN, INPUT);

  pinMode(M2_BACK_PIN, OUTPUT);
  pinMode(M2_FWD_PIN, OUTPUT);
  pinMode(M2_SPD_PIN, OUTPUT);
  pinMode(M2_ENC_A_PIN, INPUT);     //check if input pullup
  pinMode(M2_ENC_B_PIN, INPUT);

  pinMode(BUZZ_PIN, OUTPUT);
  pinMode(SW_1_PIN, INPUT_PULLUP);
  pinMode(SW_2_PIN, INPUT_PULLUP);
  pinMode(VOL_METER, INPUT);

  analogWriteFrequency(M1_BACK_PIN, 488.28);
  analogWriteFrequency(M1_FWD_PIN, 488.28);
  analogWriteFrequency(M1_SPD_PIN, 488.28);
  analogWriteFrequency(M2_BACK_PIN, 488.28);
  analogWriteFrequency(M2_FWD_PIN, 488.28);
  analogWriteFrequency(M2_SPD_PIN, 488.28);
  analogWriteFrequency(BUZZ_PIN, 488.28);

  //Interrupts
  attachInterrupt(M2_ENC_A_PIN, enc_a_l_intr_handler, FALLING); //check if rising or falling
  attachInterrupt(M2_ENC_B_PIN, enc_b_l_intr_handler, FALLING);
  attachInterrupt(M1_ENC_A_PIN, enc_a_r_intr_handler, FALLING);
  attachInterrupt(M1_ENC_B_PIN, enc_b_r_intr_handler, FALLING);
  //attachInterrupt(SW_2_PIN, sw_2_handler, FALLING);

  delay(2000);
}







#define UPPER_MOTOR_LIMIT 140
#define LOWER_MOTOR_LIMIT 30
#define PID_POLLING_DELAY 15
#define MOTOR_SWITCH_DIR_DELAY 0

//Need to test buzzer
int buzz_freq;
int last_spd;
void loop() {
  bt_write("Start Part 1");
  yellow_led_on();
  red_led_on();
  green_led_on();
  //turn_all_emit_on();
  //turn_all_led_on();
  //0 == fwd, 1 = back 2 = stop
  //move forward for 2 seconds
  set_motor_l(0, UPPER_MOTOR_LIMIT);
  set_motor_r(0, UPPER_MOTOR_LIMIT);
  //set_buzzer_on(500);
  delay(5000);
  //stop motors briefly
  set_motor_l(2, 0);
  set_motor_r(2, 0);
  delay(MOTOR_SWITCH_DIR_DELAY);
  //move motors backwards for 2 seconds
  set_motor_l(1, UPPER_MOTOR_LIMIT);
  set_motor_r(1, UPPER_MOTOR_LIMIT);
  //set_buzzer_on(1000);
  delay(5000);
  //stop motors briefly
  set_motor_l(2, 0);
  set_motor_l(2, 0);
  delay(MOTOR_SWITCH_DIR_DELAY);
  //turn left for 2 seconds
  set_motor_l(1, UPPER_MOTOR_LIMIT);
  set_motor_r(0, UPPER_MOTOR_LIMIT);
  //set_buzzer_on(2000);
  delay(5000);
  //stop motors briefly
  set_motor_l(2, 0);
  set_motor_r(2, 0);
  delay(MOTOR_SWITCH_DIR_DELAY);
  //turn right for 2 seconds
  set_motor_l(0, UPPER_MOTOR_LIMIT);
  set_motor_r(1, UPPER_MOTOR_LIMIT);
  //set_buzzer_on(5000);
  delay(5000);
  //stop motors briefly
  set_motor_l(2, 0);
  set_motor_r(2, 0);
  delay(MOTOR_SWITCH_DIR_DELAY);
  bt_write("Start Part 2");
  //Test incrementing/decrementing motor speeds
  //increment the motor speed from 0 to UPPER_MOTOR_LIMIT, then decrement it to 0
  turn_all_emit_off();
  turn_all_led_off();
  yellow_led_off();
  red_led_off();
  green_led_off();
  set_buzzer_off();
  last_spd = 0;
  for (int i = 0; i < 5; i ++) { //repeat the sequence below 5 times
    //increment speed by 1
    for (last_spd = 0; last_spd < UPPER_MOTOR_LIMIT; last_spd++) {
      set_motor_l(0, last_spd);
      set_motor_r(0, last_spd);
      get_dist_r();
      get_dist_l();
      //set_buzzer_on(7000);
      delay(PID_POLLING_DELAY);
    }
    //decrement speed by 1
    for (last_spd = UPPER_MOTOR_LIMIT; last_spd > 1; last_spd--) {
      set_motor_l(0, last_spd);
      set_motor_r(0, last_spd);
      get_dist_r();
      get_dist_l();
      //set_buzzer_on(10000);
      delay(PID_POLLING_DELAY);
    }
    //increment speed by 3
    for (last_spd = 0; last_spd < UPPER_MOTOR_LIMIT; last_spd += 3) {
      set_motor_l(0, last_spd);
      set_motor_r(0, last_spd);
      get_dist_r();
      get_dist_l();
      //set_buzzer_on(12000);
      delay(PID_POLLING_DELAY);
    }
    //decrement speed by 3
    for (last_spd = UPPER_MOTOR_LIMIT; last_spd > 1; last_spd -= 3) {
      set_motor_l(0, last_spd);
      set_motor_r(0, last_spd);
      get_dist_r();
      get_dist_l();
      //set_buzzer_on(15000);
      delay(PID_POLLING_DELAY);
    }
    //increment speed by 7
    for (last_spd = 0; last_spd < UPPER_MOTOR_LIMIT; last_spd += 7) {
      set_motor_l(0, last_spd);
      set_motor_r(0, last_spd);
      get_dist_r();
      get_dist_l();
      delay(PID_POLLING_DELAY);
    }
    //decrement speed by 7
    for (last_spd = UPPER_MOTOR_LIMIT; last_spd > 1; last_spd -= 7) {
      set_motor_l(0, last_spd);
      set_motor_r(0, last_spd);
      get_dist_r();
      get_dist_l();
      delay(PID_POLLING_DELAY);
    }
    //increment speed by 15
    for (last_spd = 0; last_spd < UPPER_MOTOR_LIMIT; last_spd += 15) {
      set_motor_l(0, last_spd);
      set_motor_r(0, last_spd);
      get_dist_r();
      get_dist_l();
      delay(PID_POLLING_DELAY);
    }
    //decrement speed by 15
    for (last_spd = UPPER_MOTOR_LIMIT; last_spd > 1; last_spd -= 15) {
      set_motor_l(0, last_spd);
      set_motor_r(0, last_spd);
      get_dist_r();
      get_dist_l();
      delay(PID_POLLING_DELAY);
    }
  }

  set_motor_l(2, 0);
  set_motor_r(2, 0);

  bt_write("Vol meter: ");
  bt_write(read_battery());


  //Serial.println(get_dist_l());

  //Serial.println(get_dist_r());


  //Serial.println(get_dist_fr());

  //Serial.println(get_dist_fl());
  //set_buzzer_on();
  //Serial.println(read_battery());
  //delay(1000);
}