#include <iostream>

#include "simulation.hpp"

int main() {
    double Kp = 10;
    double Ki = 1;
    double Kd = 0.01;
    double Ts = 0.001;

    int iter = 30000;

    PID regulator = PID(Kp, Ki, Kd, Ts);

    double setpoint = 10;

    double J = 0.3;
    double b = 0.1;
    double R = 1.0;
    double L = 0.1;
    double Kt = 0.5;
    double Ke = 0.5;

    regulator.setOutputLimits(-12.0, 12.0);

    DCMotor motor = DCMotor(J, b, R, L, Kt, Ke, Ts);
    DataLogger log;
    Simulation sim(regulator, motor, log, Ts, setpoint, iter);

    sim.addSetpointEvent(5.0, 5);
    sim.addSetpointEvent(14.0, 15);

    sim.addDisturbance(10.0, 0.5);
    sim.addDisturbance(20.0, -2.0);

    sim.run();

    log.saveToFile("../data/simulation_data.csv");
    return 0;
}