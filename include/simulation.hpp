#pragma once

#include "PID.hpp"
#include "DCMotor.hpp"
#include "DataLogger.hpp"

class Simulation{
public:
    Simulation(PID& pid, DCMotor& motor, DataLogger& logger, double Ts, double setpoint, int max_iter);

    void run();

    void setSetpoint(double setpoint);
    void reset();

    void setDisturbance(double time, double valude);

private:
    PID& pid_;
    DCMotor& motor_;
    DataLogger& logger_;
    const double Ts_;
    double setpoint_;
    int max_iter_;
    double time_;

    bool disturbance_enabled_;
    double disturbance_time_;
    double disturbance_value_;
    bool disturbance_applied_;
};