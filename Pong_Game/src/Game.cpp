#include "include/Game.h"

void playPong::runGame()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Pong Game");

	window.setFramerateLimit(60);

	sf::Event event;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		window.display();
	}
}