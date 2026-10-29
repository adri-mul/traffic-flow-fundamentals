#include "..\include\roadData.h"

void RoadData::fillDensitySamples() {
    vector<double> agentsPos = RoadData::requestAgentPositions();
    // calculate size of density sample vector
    int numberOfDensitySamples = static_cast<int>(roadLength / deltaX);
    densitySamples.reserve(numberOfDensitySamples);

    for (int window = 0; window < numberOfDensitySamples; window++) {
        double vehicleCount
        double windowDensity = (double) (3.0 / deltaX);
    }
}