#pragma once
void mov_turn_left();
void mov_turn_left();
void mov_straight_1_cell();
void mov_straight_dist(float dist);
void mov_straight_till_wall();

int get_dist_l_center();
int get_dist_r_center();
int get_dist_fl_center();
int get_dist_fr_center();

void mov_calibrate_center_values();
//private
void pid_start();
void pid_adjust();
void pid_end();

bool dist_front_has_wall();
bool dist_left_has_wall();
bool dist_right_has_wall();