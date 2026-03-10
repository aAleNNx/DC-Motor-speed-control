#include "scenarios.hpp"

#include "scenario_config.hpp"

namespace scenarios {

void runSetpointChangesScenario() {
    const SimulationConfig config;
    SimulationContext context(config);

    context.simulation.addSetpointEvent(5.0, 5.0);
    context.simulation.addSetpointEvent(14.0, 15.0);
    context.simulation.run();

    context.logger.saveToFile("../data/scenario_setpoint_changes.csv");
}

}  // namespace scenarios
