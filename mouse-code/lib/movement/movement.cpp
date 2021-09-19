#include <movement.hpp>
#include <distance_sensors.hpp>
#include <motor_control.hpp>
#include <Arduino.h>
#define WALL_R_DETECT_SENS 0.1
#define WALL_L_DETECT_SENS 0.1
static int dist_l_center;
static int dist_r_center;
static int dist_fl_center;
static int dist_fr_center;
static int center_offset_1;

int get_dist_l_center() {
    return dist_l_center;
}

int get_dist_r_center() {
    return dist_r_center;
}

int get_dist_fl_center() {
    return dist_fl_center;
}

int get_dist_fr_center() {
    return dist_fr_center;
}

void mov_calibrate_center_values() {
    dist_l_center = dist_l();
    dist_r_center = dist_r();
    dist_fl_center = dist_fr();
    dist_fr_center = dist_fl();
    center_offset_1 = dist_l_center - dist_r_center;
}
void mov_straight_1_cell() {

}

void mov_straight_dist(float dist) {

}

void mov_straight_till_wall() {
    
}


//private
void pid_start() {

}

static int old_error_P;
static int baseRspd = 45;
static int baseLspd = 40;
#define pid_D 0
#define pid_P 0.034224
void pid_adjust() {
    int left_mid = 99;
    int right_mid = 99;

    int dist_l_ = dist_l();
    int dist_r_= dist_r();
    int dist_f = dist_fr();
    float error_P;
    float error_D;
    //if(dist_left_has_wall() && dist_right_has_wall()){
    if(true){
        error_P = dist_l_ - dist_r_ - center_offset_1;
        error_D = error_P - old_error_P;    
    } else if (dist_left_has_wall()){
        error_P = 2 * (left_mid - dist_l_);
        error_D = error_P - old_error_P;
    } else if (dist_right_has_wall()){
        error_P = 2 * (right_mid - dist_r_);
        error_D = error_P - old_error_P;
    } else {
        //case where no walls use encoders
    }

    float totalError = pid_P * error_P + pid_D * error_D;
    old_error_P = error_P;
    Serial.println("Error: ");
    Serial.println(totalError);
    set_motor_l(FORWARD, baseLspd-totalError);
    set_motor_r(FORWARD, baseRspd-totalError);
    //set motor values and also base speed
}

void pid_end() {

}

bool dist_front_has_wall(){
    return false;
}
bool dist_left_has_wall(){
    int dist = dist_l();
    int threshold = (WALL_L_DETECT_SENS * dist) ;
    if(dist >= threshold){
        return true;
    } else {
        return false;
    }
}
bool dist_right_has_wall(){
    
}