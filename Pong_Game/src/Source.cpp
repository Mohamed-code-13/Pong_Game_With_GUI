#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Pong Game");

	sf::Event event;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{

		}

		window.clear();
		window.display();
	}

	return 0;
}