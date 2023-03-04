#pragma once
#include "Engine.h"

class playPong
{
public:
	sf::Text scoreTxt;

public:
	playPong();
	~playPong();

	void runGame();
	void draw();
	void move(sf::Text& scoreTxt);
	void aiMove();
	std::string getScore();

private:
	sf::RenderWindow* window;
	Player* player1, * player2;
	Ball* ball;
	sf::Font font;
};
