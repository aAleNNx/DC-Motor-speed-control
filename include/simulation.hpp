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

    void addDisturbance(double time, double load);
    void addSetpointEvent(double time, double setpoint);

    struct Disturbance
    {
        double time;
        double load;
        bool applied;
    };

    struct SetpointEvent
    {
        double time;
        double setpoint;
        bool applied;
    };
    
    

private:
    PID& pid_;
    DCMotor& motor_;
    DataLogger& logger_;
    const double Ts_;
    double setpoint_;
    int max_iter_;
    double time_;

    std::vector<Disturbance> disturbances_;
    bool disturbance_enabled_;
    std::vector<SetpointEvent> setpoint_events_;
};