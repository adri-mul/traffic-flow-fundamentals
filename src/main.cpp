#include <SFML/Graphics.hpp>
#include "../include/roadNetwork.h"
#include "../include/synthesizeNetwork.h"
#include "../include/agents.h"
#include <cmath>

// Constants
const int NUM_VERTS = 10;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const sf::Color GRAY(128, 128, 128);

// Parameters
const int NUM_AGENTS = 10;

void drawArrow(sf::RenderWindow& window, const Intersection* node1, const Intersection* node2, sf::Color color) {
	std::array line = {
		sf::Vertex{sf::Vector2f(node1->x, node1->y), color},
		sf::Vertex{sf::Vector2f(node2->x, node2->y), color}
	};
	window.draw(line.data(), line.size(), sf::PrimitiveType::Lines);

	sf::Angle angle = sf::degrees(std::atan2(node2->y - node1->y, node2->x - node1->x) * 180.0 / M_PI);

	sf::CircleShape triangle(5.f, 3);
	triangle.setRotation(angle);
	triangle.setPosition({node2->x, node2->y});

	window.draw(triangle);
}

void drawRoadNetwork(sf::RenderWindow& window, const RoadNetwork& g) {
	for (Intersection* n : g.getVertices()) {
		sf::CircleShape nodeShape(5.f);
		nodeShape.setFillColor(GRAY);
		nodeShape.setPosition({n->x-5, n->y-5});
		for (const RoadSegment* conn : n->connections) {
			std::array line = {	// defines a line between the node and its connection
				sf::Vertex{sf::Vector2f(n->x, n->y), GRAY},
				sf::Vertex{sf::Vector2f(conn->toNode->x, conn->toNode->y), GRAY}
			};
			window.draw(line.data(), line.size(), sf::PrimitiveType::Lines);
			// drawArrow(window, n, conn, GRAY);
		}
		
		window.draw(nodeShape);
	}
}

int main() {

	RoadNetwork g;
	synthesizeNetworkFromFile("../data/sample_network_highway.json", g);
	// synthesizeNetworkFromFile("../data/road_network_example.json", g);

	Agents cars;
	cars.initAgentStates(NUM_AGENTS);
	vector<int> agentPos = cars.broadcastAgentPositions();
	for (int i = 0; i < cars.numAgents; i++) {
		cout << "Agent " << i << ": x-" << agentPos[i*2] << " y-" << agentPos[i*2+1] << endl;
	}

	// sample the densities at time t=0
	RoadSegment* road = g.getVertices()[0]->connections[0];
	road->data.fillDensitySamples(agentPos, agentPos.size());
	cout << endl;
	cout << endl;
	// loop through density samples and print to console
	for (int i = 0; i < road->data.densitySamples.size(); i++) {
		cout << "Sample " << i << " density: " << road->data.densitySamples[i] << endl;
	}
	cout << endl;
	cout << endl;

	sf::RenderWindow window( sf::VideoMode( { SCREEN_WIDTH, SCREEN_HEIGHT } ), "SFML works!" );
	window.setVerticalSyncEnabled(true); 
	window.setFramerateLimit(60);
	g.displayGraph();
	while ( window.isOpen() )
	{
		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
				window.close();
		}

		window.clear(sf::Color::Green);
		
		drawRoadNetwork(window, g);
		window.display();
	}	
}
