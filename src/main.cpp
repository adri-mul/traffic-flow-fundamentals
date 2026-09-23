#include <SFML/Graphics.hpp>
#include "../include/graph.h"

int main()
{
	Graph g;
	const int numVerts = 10;
	sf::RenderWindow window( sf::VideoMode( { 200, 200 } ), "SFML works!" );
	sf::CircleShape shape( 100.f );
	shape.setFillColor( sf::Color::Green );

	while ( window.isOpen() )
	{
		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
				window.close();
		}

		window.clear();
		window.draw( shape );
		window.display();
	}

	vector<node*> verts;
	for (int i = 0; i < numVerts; i++) {
		verts.push_back(new node(3.0, 4.0));
	}

	g.addVertices(verts);
	g.displayGraph();
}