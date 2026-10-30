#include "../include/roadNetwork.h"
#include <utility>

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
    addRoadSegment(firstNode, secondNode, true);
}

// helper function created with the help of AI
double getLength(Intersection* fromNode, Intersection* toNode) {
    if (!fromNode || !toNode) return 0.0;
    double dx = toNode->x - fromNode->x;
    double dy = toNode->y - fromNode->y;
    return std::hypot(dx, dy);
}

// Function created with the help of AI
void RoadNetwork::addRoadSegment(Intersection* fromNode, Intersection* toNode, bool isOneWay) {
    RoadData data{getLength(fromNode, toNode)};
    auto segment = make_unique<RoadSegment>(RoadSegment{fromNode, toNode, 1 /* number of lanes */, isOneWay, data});
    roadSegments.push_back(std::move(segment));
    fromNode->connections.push_back(roadSegments.back().get());
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
