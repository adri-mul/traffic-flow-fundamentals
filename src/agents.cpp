#include "../include/agents.h"

vector<int> Agents::broadcastAgentPositions()
{
    return agentPositions;
}

// Gives each agent a position in x and y (stored consecutively)
void Agents::initAgentStates(int numAgents) {
    this->numAgents = numAgents;
    srand(time(0));
    // preset state 
    agentPositions.resize(numAgents * 2);
    for (int i = 0; i < numAgents; i+=1) {

        int x_pos = ((500-100) / numAgents) * i + 100;
        double x_threshold = distrCurve(x_pos);

        int x_rand = rand() % 100;
        // Places the agent on the road if the random number is below a threshold, otherwise places it at -1 (won't be counted by window)
        agentPositions[i*2] = static_cast<int>( (x_rand < x_threshold) ? x_pos : -1);
        agentPositions[i*2+1] = static_cast<int>(250);
    }

}

// Self-made distriubtion curve
double Agents::distrCurve(int x)
{
    const double c = std::sqrt(0.001);
    double term1 = 100.0 / std::hypot(1.0, c * (x - 350.0));
    double term2 = 100.0 / std::hypot(1.0, c * (x - 200));
    return term1+term2;
}
