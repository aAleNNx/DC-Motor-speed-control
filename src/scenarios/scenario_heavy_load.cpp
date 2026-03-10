#include "scenarios.hpp"

#include "scenario_config.hpp"

namespace scenarios {

void runHeavyLoadScenario() {
    const SimulationConfig config;
    SimulationContext context(config);

    context.simulation.addDisturbance(8.0, 4.0);
    context.simulation.run();

    context.logger.saveToFile("../data/scenario_heavy_load.csv");
}

}  // namespace scenarios
