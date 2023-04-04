/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini) {
   /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   **/
   this->Kp_ = Kpi;
   this->Ki_ = Kii;
   this->Kd_ = Kdi;
   this->output_lim_max_ = output_lim_maxi;
   this->output_lim_min_ = output_lim_mini;
}


void PID::UpdateError(double cte) {
   /**
   * TODO: Update PID errors based on cte.
   **/
   this->diff_cte_ = (cte - this->prev_cte_)/this->dt_;
   this->prev_cte_ = cte;
   this->int_cte_ += cte*this->dt_;
}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */
    double control = this->Kp_*this->prev_cte_ + this->Kd_*this->diff_cte_ + this->Ki_*this->int_cte_;
    if (control < this->output_lim_min_)
        control = this->output_lim_min_;
    else if(control > this->output_lim_max_)
        control = this->output_lim_max_;
    return control;
}

double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
   this->dt_ = new_delta_time;
   return this->dt_;
}