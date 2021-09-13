#include <Arduino.h>
#include <distance_sensors.hpp>
#include <motor_control.hpp>
#include <user_interface.hpp>

int enc_a_l_count = 0;
int enc_b_l_count = 0;
int enc_a_r_count = 0;
int enc_b_r_count = 0;

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

void enter_idle();

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
  enter_idle();
  delay(2000);
}







#define UPPER_MOTOR_LIMIT 140
#define LOWER_MOTOR_LIMIT 30
#define PID_POLLING_DELAY 15
#define MOTOR_SWITCH_DIR_DELAY 0

//Need to test buzzer
int buzz_freq;
int last_spd;

void enter_idle() {
  yellow_led_on();
  while(true) {
    int fr_dist = dist_fr();
    int r_dist = dist_r();
    if(r_dist >= 280 && r_dist <= 900) {
      if(fr_dist >= 200 && fr_dist <= 950){
        break;
      }
    }
    Serial.println("FR:");
    Serial.println(fr_dist);
    Serial.println("R:");
    Serial.println(r_dist);
    delay(500);
  }
  set_buzzer_on(300);
  delay(100);
  set_buzzer_off();
  delay(200);
  set_buzzer_on(1000);
  delay(100);
  set_buzzer_off();
  yellow_led_off();
}
void loop() {
  set_motor_l(FORWARD, 0);
  set_motor_r(FORWARD, 0);

  bt_write("Vol meter: ");
  bt_write(read_battery());

  delay(1000);
  //Serial.println(get_dist_l());

  //Serial.println(get_dist_r());


  //Serial.println(get_dist_fr());

  //Serial.println(get_dist_fl());
  //set_buzzer_on();
  //Serial.println(read_battery());
  //delay(1000);
}