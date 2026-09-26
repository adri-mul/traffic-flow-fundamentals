#include <SFML/Graphics.hpp>
#include "../include/roadNetwork.h"
#include "../include/synthesizeNetwork.h"
#include <random>

int main()
{
	// Constants
	const int NUM_VERTS = 10;
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	// Quick graph test
	// RoadNetwork g;
	// random_device rd;
	// mt19937 gen(rd());
	
	// for (int i = 0; i < NUM_VERTS; i++) {
	// 	g.addVertex(new node(gen() % SCREEN_WIDTH, gen() % SCREEN_HEIGHT));
	// 	if (i > 0) {
	// 		g.drawEdge(i - 1, i); // Connect each node to the previous
	// 	}
	// 	// g.drawEdge(i, i); // Connect each node to the previous
	// }
	// g.displayGraph();

	RoadNetwork g = synthesizeNetworkFromFile("../data/road_network_example.json");

	sf::RenderWindow window( sf::VideoMode( { SCREEN_WIDTH, SCREEN_HEIGHT } ), "SFML works!" );
	window.setVerticalSyncEnabled(true); 
	window.setFramerateLimit(60);

	while ( window.isOpen() )
	{
		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
				window.close();
		}

		window.clear();
		for (node* n : g.getVertices()) {
			sf::CircleShape nodeShape(5.f);
			nodeShape.setFillColor(sf::Color::Red);
			nodeShape.setPosition({n->x-5, n->y-5});
			for (const node* conn : n->connections) {
				std::array line = {	// defines a line between the node and its connection
					sf::Vertex{sf::Vector2f(n->x, n->y), sf::Color::Red},
					sf::Vertex{sf::Vector2f(conn->x, conn->y), sf::Color::Red}
				};
				window.draw(line.data(), line.size(), sf::PrimitiveType::Lines);
			}
			
			window.draw(nodeShape);
		}
		window.display();
	}	
}