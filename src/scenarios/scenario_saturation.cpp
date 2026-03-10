#include "scenarios.hpp"

#include "scenario_config.hpp"

namespace scenarios {

void runSaturationScenario() {
    SimulationConfig config;
    config.setpoint = 30.0;
    SimulationContext context(config);

    context.simulation.run();

    context.logger.saveToFile("../data/scenario_saturation.csv");
}

}  // namespace scenarios
