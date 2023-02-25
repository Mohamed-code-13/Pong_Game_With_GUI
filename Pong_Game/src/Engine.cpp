#include "include/Engine.h"

// Setting the position and the velocity to the object.
Entity::Entity(int posX, int posY, int velocityX, int velocityY)
	: posX(posX), posY(posY), velocityX(velocityX), velocityY(velocityY)
{
}

void Entity::move()
{

}

Player::Player(int posX, int posY, int velocityX, int velocityY, char color)
	: Entity(posX, posY, velocityX, velocityY)
{
	// Loading the right image for the player.
	if (color == 'R')
		tex.loadFromFile("Data/images/padRed.png");
	else
		tex.loadFromFile("Data/images/padBlue.png");
	
	// Initializing the pad with the size and position.
	pad.setSize(sf::Vector2f(50, 150));
	pad.setPosition(posX, posY);
	pad.setTexture(&tex);  // Setting the pad to the texture.
}

sf::RectangleShape Player::getPad() const
{
	return pad;
}

Ball::Ball(int posX, int posY, int velocityX, int velocityY)
	: Entity(posX, posY, velocityX, velocityY)
{
	tex.loadFromFile("Data/images/ball.png");  // Loading the ball image.

	// Initializing the pad with the size and position.
	ball.setSize(sf::Vector2f(50, 50));
	ball.setPosition(posX, posY);
	ball.setTexture(&tex);  // Setting the pad to the texture.
	
	// Loading the sound buffers.
	buff_hitPad.loadFromFile("Data/sounds/hitPad.wav");
	buff_hitWall.loadFromFile("Data/sounds/hitWall.wav");
	buff_Score.loadFromFile("Data/sounds/score.wav");

	// Converting the sound buffers to actual sounds.
	hitPad.setBuffer(buff_hitPad);
	hitWall.setBuffer(buff_hitWall);
	Score.setBuffer(buff_Score);
}

sf::RectangleShape Ball::getPad() const
{
	return ball;
}
