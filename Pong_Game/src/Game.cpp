#include "include/Game.h"

playPong::playPong()
{
	// Initializing the window and the game objects on the heap.
	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Pong Game");

	player1 = new Player(50, HEIGHT / 2 - 100, 0, 5, 'R');
	player2 = new Player(WIDTH - 100, HEIGHT / 2 - 100, 0, 5, 'B');
	ball = new Ball(WIDTH / 2, HEIGHT / 2, 3, 3);
}

playPong::~playPong()
{
	// Freeing meomry.
	delete window;

	delete player1;
	delete player2;
	delete ball;
}

void playPong::runGame()
{
	window->setFramerateLimit(FPS);  // Setting a frame rate limit.

	sf::Event event;
	while (window->isOpen())
	{
		// Handling Players' events.
		while (window->pollEvent(event))
		{
			// Closing the window.
			if (event.type == sf::Event::Closed)
				window->close();
		}

		// Drawing the window.
		draw();
	}
}

void playPong::draw()
{
	window->clear();  // Clearing the window.

	// Drawing the two players and the ball.
	window->draw(player1->getPad());
	window->draw(player2->getPad());
	window->draw(ball->getPad());
	
	window->display();  // Displaying on the window.
}