#include "DCMotor.hpp"

#include <assert.h>
#include <iostream>

DCMotor::DCMotor(double J, double b, double K, double Ts):
    J_(J),
    b_(b),
    K_(K),
    Ts_(Ts),
    omega_(0.0),
    load_torque_(0.0)
{
    assert(Ts > 0.0);
    assert(J > 0.0);
}

void DCMotor::step(double voltage){
    double torque_motor = K_ * voltage;
    double net_torque = torque_motor - b_ * omega_ - load_torque_;
    double acceleration = net_torque / J_;
    omega_ += Ts_ * acceleration; 
}

void DCMotor::setLoadTorque(double Tl){
    load_torque_ = Tl;
}

double DCMotor::getSpeed() const{
    return omega_;
}

void DCMotor::reset(){
    omega_ = 0.0;
    load_torque_ = 0.0;
}