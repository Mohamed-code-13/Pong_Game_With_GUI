#pragma once
#include "Engine.h"

class playPong
{
public:
	playPong();
	~playPong();

	void runGame();
	void draw();
	void move();
	void aiMove();

private:
	sf::RenderWindow* window;
	Player* player1, * player2;
	Ball* ball;
};
