#pragma once

void mov_turn_left();
void mov_turn_left();
void mov_straight_1_cell();
void mov_straight_dist(float dist);
void mov_straight_till_wall();


//private
void pid_start();
void pid_adjust(float speed);
void pid_end();