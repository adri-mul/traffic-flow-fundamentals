#include "../include/synthesizeNetwork.h"

using namespace std;

// Function created with the help of AI
void synthesizeNetworkFromFile(const std::string& filename, RoadNetwork& g) {
    ifstream infile;
    infile.open(filename);
    if (!infile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    try {
        using json = nlohmann::json;
        const json network = json::parse(infile);
        const json& intersections = network.at("intersections");
        const json& roads = network.at("roads");

        if (!intersections.is_array() || !roads.is_array()) {
            throw std::runtime_error("'intersections' and 'roads' must be arrays");
        }

        // vector<unique_ptr<Intersection>> ownedNodes;  // list of nodes with unique_ptr attached to them (used to clean up at the end)
        vector<Intersection*> vertices;
        unordered_map<int, Intersection*> nodesById;
        // ownedNodes.reserve(intersections.size());
        vertices.reserve(intersections.size());

        for (const json& intersection : intersections) {
            const int id = intersection.at("id").get<int>();
            const string name = intersection.at("name").get<string>();
            const double x = intersection.at("x").get<double>();
            const double y = intersection.at("y").get<double>();

            Intersection* intersectionNode = new Intersection(id, name, x, y);
            if (!nodesById.emplace(id, intersectionNode).second) { // If the map has more than one element with key 'id', .second returns false (fail)
                throw std::runtime_error("Duplicate intersection id: " + to_string(id));
            }
            // Add the nodes
            vertices.push_back(intersectionNode);
            // ownedNodes.push_back(move(intersectionNode));
        }


        for (const json& road : roads) {
            const json& endpoints = road.at("intersections");
            if (!endpoints.is_array() || endpoints.size() != 2) {
                throw std::runtime_error("Each road must reference exactly two intersections");
            }

            const int firstId = endpoints.at(0).get<int>();
            const int secondId = endpoints.at(1).get<int>();
            const auto firstNode = nodesById.find(firstId);
            const auto secondNode = nodesById.find(secondId);
            if (firstNode == nodesById.end() || secondNode == nodesById.end()) {
                throw std::runtime_error("Road references an unknown intersection");
            }
            
            // for (const auto& networkNode : firstNode->second->connections) {
            //     cout << "(" << networkNode->toNode->x << ", " << networkNode->toNode->y << ")";
            // }
            // cout << endl;
            const bool isOneWay = road.at("directional").get<bool>();
            g.addRoadSegment(firstNode->second, secondNode->second, isOneWay);
            if (!isOneWay) {
                g.addRoadSegment(secondNode->second, firstNode->second, false);
            }

        }

        g.addVertices(vertices);
        cout << "Vertices size: " << g.getVertices().size() << endl;
        // g.displayGraph();

        // for (unique_ptr<Intersection>& intersectionNode : ownedNodes) {
        //     intersectionNode.release();
        // }
        infile.close();
    } catch (const std::exception& error) {
        std::cerr << "Error parsing road network: " << error.what() << std::endl;
    }
}