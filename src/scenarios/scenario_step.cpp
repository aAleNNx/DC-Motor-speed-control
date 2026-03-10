#include "scenarios.hpp"

#include "scenario_config.hpp"

namespace scenarios {

void runStepScenario() {
    const SimulationConfig config;
    SimulationContext context(config);

    context.simulation.addSetpointEvent(0.0, 0.0);
    context.simulation.addSetpointEvent(5.0, 10.0);
    context.simulation.run();

    context.logger.saveToFile("../data/scenario_step.csv");
}

}  // namespace scenarios
