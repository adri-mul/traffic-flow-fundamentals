#include "..\include\roadData.h"

RoadData::RoadData(double roadLength, int roadStart=0, int roadEnd=0)
{
    this->roadLength = roadLength;
    this->roadStart = roadStart;
    this->roadEnd = roadEnd;
}

void RoadData::fillDensitySamples(vector<int> agentsPos, int numAgents)
{
    // calculate size of density sample vector (number of samples)
    int numberOfDensitySamples = static_cast<int>(roadLength / deltaX);
    densitySamples.reserve(numberOfDensitySamples);
    
    // loop slides the window in discrete steps based on the road length and window size
    for (int window = 0; window < numberOfDensitySamples; window++) {
        int vehicleCountInWindow = 0;
        for (int i = 0; i < numAgents; i++) {
            // agent's position must be within the window to be counted
            // i * 2 because agentsPos stores [agent1X, agent1Y, agent2X, agent2Y, ...]
            if (agentsPos[i*2] >= roadStart + window * deltaX && agentsPos[i*2] < roadStart + (window + 1) * deltaX) {
                vehicleCountInWindow++;
            }
        }
        
        double windowDensity = static_cast<double>(vehicleCountInWindow / deltaX); // deltaX represents the window size
        densitySamples.push_back(windowDensity);    // captures and saves the window density
    }
}
