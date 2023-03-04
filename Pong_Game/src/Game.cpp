#include "include/Game.h"

playPong::playPong()
{
	// Initializing the game window.
	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Pong Game");

	// Initializing the players and the ball.
	player1 = new Player(50, HEIGHT / 2 - 80, 0, 0, 'R');
	player2 = new Player(WIDTH - 100, HEIGHT / 2 - 80, 0, 0, 'B');
	ball = new Ball(WIDTH / 2 - 35, HEIGHT / 2 - 35, -5, -3);

	// Initializing the score and text.
	font.loadFromFile("Data/oswald.ttf");
	scoreTxt.setFont(font);
	scoreTxt.setCharacterSize(50);
	scoreTxt.setFillColor(sf::Color::White);
	scoreTxt.setPosition(WIDTH / 2 - 30, 20);
	scoreTxt.setString("0 - 0");
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
			
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::W)
					player1->setVelocity(0, -5);
				
				if (event.key.code == sf::Keyboard::S)
					player1->setVelocity(0, 5);

			}

			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::S)
					player1->setVelocity(0, 0);
			}
		}

		// Moving
		move(scoreTxt);

		// Drawing the window.
		draw();
	}
}

void playPong::draw()
{
	window->clear();  // Clearing the window.

	// Drawing the two players, the ball and the text.
	window->draw(player1->getPad());
	window->draw(player2->getPad());
	window->draw(ball->getPad());
	window->draw(scoreTxt);
	
	window->display();  // Displaying on the window.
}

void playPong::move(sf::Text& scoreTxt)
{
	player1->move();
	ball->move(*player1, *player2, scoreTxt);

	aiMove();

	player2->move();
}

void playPong::aiMove()
{
	int player_Y_Pos = player2->getPosY();
	int ball_Y_Pos = ball->getPosY();

	if (ball_Y_Pos > player_Y_Pos + 40)
	{
		player2->setVelocity(0, 5);
	}
	else if (ball_Y_Pos < player_Y_Pos + 20)
	{
		player2->setVelocity(0, -5);
	}
	else
	{
		player2->setVelocity(0, 0);
	}
}

std::string playPong::getScore()
{
	return "";
}
