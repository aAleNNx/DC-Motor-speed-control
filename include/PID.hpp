#pragma once

#include <iostream>

class PID{
public:
    PID(double kp, double ki, double kd, double Ts);

    double update(double setpoint, double measurement);

    void setOutputLimits(double min, double max);
    void reset();

private:
    double kp_;
    double ki_;
    double kd_;
    
    const double Ts_;

    double integrator_;
    double prev_measurement_;

    double min_output_;
    double max_output_;

    bool first_run_;
};