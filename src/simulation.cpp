#include "simulation.hpp"

#include <iostream>

Simulation::Simulation(PID& pid, DCMotor& motor, DataLogger& logger, double Ts, double setpoint, int max_iter):
    pid_(pid),
    motor_(motor),
    logger_(logger),
    Ts_(Ts),
    setpoint_(setpoint),
    max_iter_(max_iter),
    time_(0.0),
    disturbance_enabled_(false),
    disturbance_time_(0.0),
    disturbance_value_(0.0),
    disturbance_applied_(false)
{}

void Simulation::run(){
    for(int i = 0; i < max_iter_; i++){
        double u = pid_.update(setpoint_, motor_.getSpeed());
        motor_.step(u);

        if(disturbance_enabled_ && !disturbance_applied_ && time_ >= disturbance_time_){
            motor_.setLoadTorque(disturbance_value_);
            disturbance_applied_ = true;
        }
        logger_.log(time_, setpoint_, motor_.getSpeed(), u);
        time_ += Ts_;
    }
    std::cout << "Simulation completed. Data logged for " << max_iter_ << " iterations." << std::endl;
}

void Simulation::setSetpoint(double setpoint){
    setpoint_ = setpoint;
}

void Simulation::reset(){
    pid_.reset();
    motor_.reset();
    time_ = 0.0;
}

void Simulation::setDisturbance(double time, double value){
    disturbance_enabled_ = true;
    disturbance_time_ = time;
    disturbance_value_ = value;
    disturbance_applied_ = false;
}