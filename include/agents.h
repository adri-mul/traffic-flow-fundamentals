#pragma once

struct Agents {
    public:
        void broadcastAgentPositions(double* positions, int numAgents);  // positions is an array of the x,y coordinates for n agents. Thus, the array size is numAgents * 2
        void initAgents(int numAgents);
};