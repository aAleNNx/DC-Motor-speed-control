#pragma once

class DCMotor {
public:
    DCMotor(double J, double b, double R, double L, double Kt, double Ke, double Ts);

    void step(double Voltage);

    void addLoadTorque(double Tl);
    void reset();

    double getSpeed() const;
    double getVoltage() const;
    double getCurrent() const;
    double getLoadTorque() const;


private:
    const double J_;
    const double b_;

    const double R_;
    const double L_;

    const double Kt_;
    const double Ke_;

    const double Ts_;

    double omega_;
    double current_;

    double load_torque_;
};