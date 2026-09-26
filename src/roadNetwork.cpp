#include "../include/roadNetwork.h"

void RoadNetwork::addVertex(node* n) {
    verts.push_back(n);
}

void RoadNetwork::addVertices(vector<node*> nodes) {
    for(node* n : nodes) {
        verts.push_back(n);
    }
}

void RoadNetwork::drawEdge(int n1, int n2) {
    node* firstNode = verts[n1];
    node* secondNode = verts[n2];
    firstNode->connections.push_back(secondNode);
}

// text-based graph display
void RoadNetwork::displayGraph() {
    for (node* n : verts) {
        cout << "Node: (" << n->x << ", " << n->y << ") --> ";
        for (const node* conn : n->connections) {
            cout << "(" << conn->x << ", " << conn->y << ") ";
        }
        cout << endl;
    }
}

node::node(double x, double y) {
    this->id = -1;
    this->x = x;
    this->y = y;
    this->flag = 0;
}

node::node(int id, const string& name, double x, double y)
    : id(id), name(name), x(x), y(y), flag(0) {}