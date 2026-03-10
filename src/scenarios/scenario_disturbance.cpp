#include "scenarios.hpp"

#include "scenario_config.hpp"

namespace scenarios {

void runDisturbanceScenario() {
    const SimulationConfig config;
    SimulationContext context(config);

    context.simulation.addDisturbance(10.0, 0.5);
    context.simulation.addDisturbance(20.0, -2.0);
    context.simulation.run();

    context.logger.saveToFile("../data/scenario_disturbance.csv");
}

}  // namespace scenarios
