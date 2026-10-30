#pragma once

#include <vector>
#include <iostream>

using namespace std;

/*
Collects data from a RoadSegment every delta t time (delta t defined in main.cpp)
* Requests agents position data
* Gets road length from RoadSegment on initialization (doesn't change)
*/

struct RoadData {
    double roadLength; // placeholder, will collect from RoadSegment eventually
    double deltaX = 10; // sliding window, defaults to 10px
    vector<double> densitySamples;
    // constructor
    RoadData(double roadLength);
    // Functions
    void fillDensitySamples(vector<int> agentsPos, int numAgents);
};