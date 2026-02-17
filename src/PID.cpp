#include <algorithm>

#include "PID.hpp"


PID::PID(double kp, double ki, double kd, double Ts):
    kp_(kp),
    ki_(ki),
    kd_(kd),
    Ts_(Ts),
    integrator_(0.0),
    prev_measurement_(0.0),
    min_output_(-1e9),
    max_output_(1e9),
    integrator_enabled_(true)
{};

double PID::update(double setpoint, double measurement){
    double error = setpoint - measurement;
    double P = kp_ * error;
    double D = -kd_ * (measurement - prev_measurement_) / Ts_;
    
    double integrator_candidate = integrator_ + Ts_ * error;
    double u_raw = P + D + ki_ * integrator_candidate;
    double u_clamped = std::clamp(u_raw, min_output_, max_output_);

    if (u_raw == u_clamped){
        integrator_ = integrator_candidate;
    }
    else{
        if((u_raw > max_output_ and error < 0) or (u_raw < min_output_ and error > 0)){
            integrator_ = integrator_candidate;
        }
    }

    prev_measurement_ = measurement;

    return u_clamped;
};