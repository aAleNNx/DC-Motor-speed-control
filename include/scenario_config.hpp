#pragma once

#include "DataLogger.hpp"
#include "DCMotor.hpp"
#include "PID.hpp"
#include "simulation.hpp"

namespace scenarios {

struct SimulationConfig {
    double Kp = 10.0;
    double Ki = 1.0;
    double Kd = 0.01;
    double Ts = 0.001;
    double time = 30.0;
    double setpoint = 10.0;
    double min_output = -12.0;
    double max_output = 12.0;

    double J = 0.3;
    double b = 0.1;
    double R = 1.0;
    double L = 0.1;
    double Kt = 0.5;
    double Ke = 0.5;

    int iterations() const {
        return static_cast<int>(time / Ts);
    }
};

struct SimulationContext {
    PID regulator;
    DCMotor motor;
    DataLogger logger;
    Simulation simulation;

    explicit SimulationContext(const SimulationConfig& config)
        : regulator(config.Kp, config.Ki, config.Kd, config.Ts),
          motor(config.J, config.b, config.R, config.L, config.Kt, config.Ke, config.Ts),
          logger(),
          simulation(regulator, motor, logger, config.Ts, config.setpoint, config.iterations()) {
        regulator.setOutputLimits(config.min_output, config.max_output);
    }
};

}  // namespace scenarios
