#pragma once
#include "Engine.h"

// The width and the height of the game.
#define WIDTH 1000
#define HEIGHT 600
#define FPS 60

class playPong
{
public:
	playPong();
	~playPong();

	void runGame();
	void draw();

private:
	sf::RenderWindow* window;
	Player* player1, * player2;
	Ball* ball;
};
