#include <iostream>

#include "simulation.hpp"

int main() {
    double Kp = 1.5;
    double Ki = 3;
    double Kd = 0.01;
    double Ts = 0.01;

    int iter = 100;

    PID regulator = PID(Kp, Ki, Kd, Ts);

    double setpoint = 10;

    double J = 0.1;
    double b = 0.1;
    double K = 0.5;

    regulator.setOutputLimits(-12.0, 12.0);

    DCMotor motor = DCMotor(J, b, K, Ts);

    Simulation sim = Simulation(regulator, motor, Ts, setpoint, iter);
    sim.run();
    return 0;
}