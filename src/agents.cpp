#include "../include/agents.h"

vector<int> Agents::broadcastAgentPositions()
{
    return agentPositions;
}

// Gives each agent a position in x and y (stored consecutively)
void Agents::initAgentStates(int numAgents) {
    this->numAgents = numAgents;
    // preset state 
    agentPositions.resize(numAgents * 2);
    for (int i = 0; i < numAgents; i+=1) {
        agentPositions[i*2] = static_cast<int>(std::min(100 + i * 3, 500));
        agentPositions[i*2+1] = static_cast<int>(250);
    }

}
