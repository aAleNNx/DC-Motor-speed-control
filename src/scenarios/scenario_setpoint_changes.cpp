#include "scenarios.hpp"

#include "DataLogger.hpp"
#include "DCMotor.hpp"
#include "PID.hpp"
#include "simulation.hpp"

namespace scenarios {

void runSetpointChangesScenario() {
    constexpr double Kp = 10.0;
    constexpr double Ki = 1.0;
    constexpr double Kd = 0.01;
    constexpr double Ts = 0.001;
    constexpr int iterations = 30000;
    constexpr double setpoint = 10.0;

    constexpr double J = 0.3;
    constexpr double b = 0.1;
    constexpr double R = 1.0;
    constexpr double L = 0.1;
    constexpr double Kt = 0.5;
    constexpr double Ke = 0.5;

    PID regulator(Kp, Ki, Kd, Ts);
    regulator.setOutputLimits(-12.0, 12.0);

    DCMotor motor(J, b, R, L, Kt, Ke, Ts);
    DataLogger logger;
    Simulation simulation(regulator, motor, logger, Ts, setpoint, iterations);

    simulation.addSetpointEvent(5.0, 5.0);
    simulation.addSetpointEvent(14.0, 15.0);
    simulation.run();

    logger.saveToFile("../data/scenario_setpoint_changes.csv");
}

}  // namespace scenarios
