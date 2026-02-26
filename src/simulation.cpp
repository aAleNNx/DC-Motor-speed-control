#include "simulation.hpp"

#include <iostream>

Simulation::Simulation(PID& pid, DCMotor& motor, DataLogger& logger, double Ts, double setpoint, int max_iter):
    pid_(pid),
    motor_(motor),
    logger_(logger),
    Ts_(Ts),
    setpoint_(setpoint),
    max_iter_(max_iter),
    time_(0.0)
{}

void Simulation::run(){
    for(int i = 0; i < max_iter_; i++){
        double u = pid_.update(setpoint_, motor_.getSpeed());
        motor_.step(u);

        std::cout << "time: " << time_
        << "    measurement: " << motor_.getSpeed()
        << "    control: " << u << std::endl;
        logger_.log(time_, setpoint_, motor_.getSpeed(), u);
        time_ += Ts_;
    }
}

void Simulation::setSetpoint(double setpoint){
    setpoint_ = setpoint;
}

void Simulation::reset(){
    pid_.reset();
    motor_.reset();
    time_ = 0.0;
}