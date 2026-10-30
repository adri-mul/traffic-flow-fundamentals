#pragma once

#include <vector>
#include <iostream>
#include <memory>
#include <string>
#include <cmath>

#include "roadData.h"

using namespace std;

/*
Flag codes: 0xXXXX
0x000X
    * 0-4 = number of intersections, starting from East
    * 5 = 
0x00X0
    * 0-9 = number of intersections
*/

struct RoadSegment;

struct Intersection {
    Intersection(double x, double y);
    Intersection(int id, const string& name, double x, double y);
    int id;
    string name;
    vector<RoadSegment*> connections;
    double x;
    double y;
    short flag;
    double densityAtIntersection();
    private:
        double singleLaneEddieDensity();
};

struct RoadSegment {
    Intersection* fromNode;
    Intersection* toNode;
    short numLanes = 1;
    bool isOneWay = false;
    RoadData data;
    
};

// Class to represent a road network through a graph
class RoadNetwork {
    private:
        vector<Intersection*> verts;
        vector<unique_ptr<RoadSegment>> roadSegments;
    public:
        void addVertices(vector<Intersection*> nodes);
        void addVertex(Intersection* n);
        void drawEdge(int n1, int n2);
        void addRoadSegment(Intersection* fromNode, Intersection* toNode, bool isOneWay);
        vector<Intersection*> getVertices() const { return verts; }
        void displayGraph();
        vector<Intersection*> pathfind_bfs(Intersection* start, Intersection* end);
};
