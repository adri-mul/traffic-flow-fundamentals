#pragma once

#include <vector>
#include <queue>

using namespace std;
struct node {
    vector<node*> connections;
    double x;
    double y;
    int flag;
};

class Graph {
    private:
        vector<node> verts;
    public:
        void* addVertices(vector<node> nodes);
        void* addVertices(node n);
        void* drawEdge(int n1, int n2);
        void* displayGraph();
};