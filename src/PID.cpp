#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  initialized = false;
  prev_cte = 0;

  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
	this->dKp = 0.1*Kp;
  this->dKi = 0.1*Ki;
  this->dKd = 0.1*Kd;

  p_error = 0;
  i_error = 0;
  d_error = 0;

  this->status = STATUS_INIT;
  this->p_id = 0;

  this->best_err = 0;
  this->error = 0;
  this->counter = 0;
}

void PID::UpdateError(double cte) {

  if (!initialized)
  {
    prev_cte = cte;
    initialized = true;
  }

  p_error = cte;
  d_error = cte - prev_cte;
  i_error += cte;
  prev_cte = cte;

  // Twiddle
  error += cte*cte;
}

void PID::refresh()
{
  p_error = 0;
  i_error = 0;
  d_error = 0;

  this->error = 0;
  this->counter++;
}

double PID::TotalError() {

  return i_error;
}
