#pragma once

#include <vector>
#include <iostream>
#include <string>

using namespace std;
struct node {
    node(double x, double y);
    node(int id, const string& name, double x, double y);
    int id;
    string name;
    vector<node*> connections;
    double x;
    double y;
    int flag;
};

class RoadNetwork {
    private:
        vector<node*> verts;
    public:
        void addVertices(vector<node*> nodes);
        void addVertex(node* n);
        void drawEdge(int n1, int n2);
        vector<node*> getVertices() { return verts; }
        void displayGraph();
};