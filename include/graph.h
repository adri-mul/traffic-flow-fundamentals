#pragma once

#include <vector>
#include <queue>
#include <iostream>

using namespace std;
struct node {
    node(double x, double y);
    vector<node*> connections;
    double x;
    double y;
    int flag;
};

class Graph {
    private:
        vector<node*> verts;
    public:
        void* addVertices(vector<node*> nodes);
        void* addVertices(node* n);
        void* drawEdge(int n1, int n2);
        void* displayGraph();
};