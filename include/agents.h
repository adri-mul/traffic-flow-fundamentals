#pragma once

#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct Agents {
    public:
        int numAgents;
        vector<int> broadcastAgentPositions();  // positions is an array of the x,y coordinates for n agents. Thus, the array size is numAgents * 2
        /*
        Initializes Agent States randomly based on a seed
         */
        void initAgentStates(int numAgents);
    private:
        vector<int> agentPositions;
};