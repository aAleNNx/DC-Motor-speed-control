#pragma once

#include "PID.hpp"
#include "DCMotor.hpp"

class Simulation{
public:
    Simulation(PID& pid, DCMotor& motor, double Ts, double setpoint, int max_iter);

    void run();

    void setSetpoint(double setpoint);
    void reset();

private:
    PID& pid_;
    DCMotor& motor_;
    const double Ts_;
    double setpoint_;
    int max_iter_;
    double time_;
};