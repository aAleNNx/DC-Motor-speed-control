#include <algorithm>
#include <assert.h>
#include <limits>
#include <cmath>

#include "PID.hpp"


PID::PID(double kp, double ki, double kd, double Ts):
    
    kp_(kp),
    ki_(ki),
    kd_(kd),
    Ts_(Ts),
    integrator_(0.0),
    prev_measurement_(0.0),
    min_output_(-std::numeric_limits<double>::infinity()),
    max_output_(std::numeric_limits<double>::infinity()),
    first_run_(true)
{
    assert(Ts > 0.0);
}

double PID::update(double setpoint, double measurement){
    if(first_run_){
        prev_measurement_ = measurement;
        first_run_ = false;
    }
    
    double error = setpoint - measurement;
    double P = kp_ * error;
    double D = -kd_ * (measurement - prev_measurement_) / Ts_;
    
    double integrator_candidate = integrator_ + Ts_ * error;
    double u_raw = P + D + ki_ * integrator_candidate;
    double u_clamped = std::clamp(u_raw, min_output_, max_output_);

    if (std::abs(u_raw - u_clamped) <= 1e-9){
        integrator_ = integrator_candidate;
    }
    else{
        if((u_raw > max_output_ && error < 0) || (u_raw < min_output_ && error > 0)){
            integrator_ = integrator_candidate;
        }
    }

    prev_measurement_ = measurement;

    return u_clamped;
}

void PID::setOutputLimits(double min_output, double max_output){
    assert(min_output <= max_output);
    min_output_ = min_output;
    max_output_ = max_output;
}

void PID::reset(){
    integrator_ = 0.0;
    prev_measurement_ = 0.0;
    first_run_ = true;
}