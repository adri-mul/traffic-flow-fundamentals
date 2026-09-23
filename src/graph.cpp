#include "../include/graph.h"

void* Graph::addVertices(node* n) {
    verts.push_back(n);
}

void* Graph::addVertices(vector<node*> nodes) {
    for(node* n : nodes) {
        verts.push_back(n);
    }
}

void* Graph::drawEdge(int n1, int n2) {
    node* firstNode = verts.at(n1);
    node* secondNode = verts.at(n2);
    firstNode->connections.push_back(secondNode);
}

// text-based graph display
void* Graph::displayGraph() {
    for (node* n : verts) {
        cout << "Node:" << n->x << ", " << n->y << " --> ";
        for (const node* conn : n->connections) {
            cout << "(" << conn->x << ", " << conn->y << ") ";
        }
        cout << endl;
    }
}

node::node(double x, double y) {
    this->x = x;
    this->y = y;
}