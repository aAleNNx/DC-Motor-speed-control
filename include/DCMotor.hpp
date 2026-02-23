#pragma once

#include <iostream>

class DCMotor {
public:
    DCMotor(double J, double b, double K, double Ts);

    void step(double Voltage);
    void setLoadTorque(double Tl);
    double getSpeed() const;
    void reset();


private:
    const double J_;
    const double b_;
    const double K_;
    const double Ts_;

    double omega_;
    double load_torque_;

};