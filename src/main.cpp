#include "scenarios.hpp"

int main() {
    scenarios::runStepScenario();
    scenarios::runSetpointChangesScenario();
    scenarios::runHeavyLoadScenario();
    scenarios::runSaturationScenario();
    scenarios::runDisturbanceScenario();
    return 0;
}
