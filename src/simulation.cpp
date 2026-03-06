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
    disturbance_enabled_(false)
{}

void Simulation::run(){
    for(int i = 0; i < max_iter_; i++){
        double u = pid_.update(setpoint_, motor_.getSpeed());
        motor_.step(u);

        if(disturbance_enabled_){
            for(auto& dist : disturbances_){
                if(!dist.applied && time_ >= dist.time){
                    motor_.addLoadTorque(dist.load);
                    dist.applied = true;
                }
            }
        }
        
        for(auto& event : setpoint_events_){
            if(!event.applied && time_ >= event.time){
                setSetpoint(event.setpoint);
                event.applied = true;
            }
        }
        logger_.log(time_, setpoint_, motor_.getSpeed(), u, motor_.getLoadTorque());
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
    disturbances_.clear();
    disturbance_enabled_ = false;
}

void Simulation::addDisturbance(double time, double load){
    disturbances_.push_back({time, load, false});
    disturbance_enabled_ = true;
}

void Simulation::addSetpointEvent(double time, double setpoint){
    setpoint_events_.push_back({time, setpoint, false});
}