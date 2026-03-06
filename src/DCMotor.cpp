#include "DCMotor.hpp"

#include <assert.h>
#include <iostream>
#include <algorithm>

DCMotor::DCMotor(double J, double b, double R, double L, double Kt, double Ke, double Ts):
    J_(J),
    b_(b),
    R_(R),
    L_(L),
    Kt_(Kt),
    Ke_(Ke),
    Ts_(Ts),
    omega_(0.0),
    load_torque_(0.0),
    current_(0.0)
{
    assert(Ts > 0.0);
    assert(J > 0.0);
}

void DCMotor::step(double voltage){
    voltage = std::clamp(voltage, -12.0, 12.0);
    double dI = (voltage - R_*current_ - Ke_*omega_) / L_;
    current_ += Ts_ * dI;
    double torque_motor = Kt_ * current_;
    double net_torque = torque_motor - b_ * omega_ - load_torque_;
    double acceleration = net_torque / J_;
    omega_ += Ts_ * acceleration; 
}

void DCMotor::addLoadTorque(double Tl){
    load_torque_ += Tl;
}

double DCMotor::getLoadTorque() const{
    return load_torque_;
}

double DCMotor::getSpeed() const{
    return omega_;
}

double DCMotor::getVoltage() const{
    return R_ * current_ + Ke_ * omega_;
}

void DCMotor::reset(){
    omega_ = 0.0;
    current_ = 0.0;
    load_torque_ = 0.0;
}