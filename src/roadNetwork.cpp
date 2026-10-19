#include "../include/roadNetwork.h"

void RoadNetwork::addVertex(Intersection* n) {
    verts.push_back(n);
}

void RoadNetwork::addVertices(vector<Intersection*> nodes) {
    for(Intersection* n : nodes) {
        verts.push_back(n);
    }
}

void RoadNetwork::drawEdge(int n1, int n2) {
    Intersection* firstNode = verts[n1];
    Intersection* secondNode = verts[n2];
    RoadSegment road {firstNode, secondNode};
    firstNode->connections.push_back(&road);
}

// text-based graph display
void RoadNetwork::displayGraph() {
    for (Intersection* n : verts) {
        cout << "Node: (" << n->x << ", " << n->y << ") --> ";
        for (const RoadSegment* conn : n->connections) {
            cout << "(" << conn->toNode->x << ", " << conn->toNode->y << ") ";
        }
        cout << endl;
    }
}

vector<Intersection *> RoadNetwork::pathfind_bfs(Intersection *start, Intersection *end)
{
    
    return vector<Intersection *>();
}

Intersection::Intersection(double x, double y) {
    this->id = -1;
    this->x = x;
    this->y = y;
    this->flag = 0;
}

Intersection::Intersection(int id, const string& name, double x, double y)
    : id(id), name(name), x(x), y(y), flag(0) {}

double Intersection::densityAtIntersection()
{
    return 0.0;
}

double Intersection::singleLaneEddieDensity()
{
    return 0.0;
}
