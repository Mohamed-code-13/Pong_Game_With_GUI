#include "include/Engine.h"

// Setting the position and the velocity to the object.
Entity::Entity(int posX, int posY, int velocityX, int velocityY)
	: posX(posX), posY(posY), velocityX(velocityX), velocityY(velocityY)
{
}


std::pair<int, int> Entity::getVelocity() const
{
	return { velocityX, velocityY };
}

void Entity::setVelocity(int velX, int velY)
{
	velocityX = velX;
	velocityY = velY;
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
	pad.setSize(sf::Vector2f(30, 150));
	pad.setPosition(posX, posY);
	pad.setTexture(&tex);  // Setting the pad to the texture.
}

// Handling Player move.
void Player::move()
{
	pad.move(velocityX, velocityY);

	// Checking if player goes out of bound.
	if (getPosY() < 0)
		pad.setPosition(getPosX(), 0);

	// Checking if player goes out of bound.
	if (getPosY() + 150 > HEIGHT)
		pad.setPosition(getPosX(), HEIGHT - 150);
}

sf::RectangleShape Player::getPad() const
{
	return pad;
}

int Player::getPosX() const
{
	return pad.getPosition().x;
}

int Player::getPosY() const
{
	return pad.getPosition().y;
}

void Player::setPos(int posX, int posY)
{
	pad.setPosition(posX, posY);
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

// Handling ball move.
void Ball::move(Player& player1, Player& player2)
{
	ball.move(velocityX, velocityY);

	handleHittingWall();

	handleWinning(player1, player2);

	handleCollision(player1, player2);
}

void Ball::handleCollision(Player& player1, Player& player2)
{
	if (ball.getGlobalBounds().intersects(player1.getPad().getGlobalBounds()) ||
		ball.getGlobalBounds().intersects(player2.getPad().getGlobalBounds()))
	{
		if (velocityX > 0)
			velocityX += 1;
		else
			velocityX -= 1;
		/*
		player1.setVelocity(0, player1.getVelocity().second + 1);
		player2.setVelocity(0, player2.getVelocity().second + 1);
		*/
		velocityX *= -1;  // changing the direction of Y.
		hitPad.play();  // Playing the hit wall sound.
	}
}

void Ball::handleWinning(Player& player1, Player& player2)
{
	// Checking if the ball is out of bound (A player lost).
	if (getPosX() + 35 < 0 || getPosX() > WIDTH)
	{
		// Checking if Player 1 lost.
		if (getPosX() + 35 < 0)
		{
			// Setting the default velocities.
			velocityX = 5;
			velocityY = 3;
		}
		// Checking if Player 2 lost.
		else if (getPosX() > WIDTH)
		{
			// Setting the default velocities.
			velocityX = -5;
			velocityY = -3;
		}

		// Setting the default position.
		ball.setPosition(WIDTH / 2 - 35, HEIGHT / 2 - 35);
	
		// Setting the default positions
		player1.setPos(player1.getPosX(), HEIGHT / 2 - 80);
		player2.setPos(player2.getPosX(), HEIGHT / 2 - 80);

		/*
		player1.setVelocity(0, 0);
		player2.setVelocity(0, 0);
		*/

		// Playing the score sound.
		Score.play();
	}
}

void Ball::handleHittingWall()
{
	// Checking if the ball hit the wall.
	if (getPosY() < 0 || getPosY() + 50 > HEIGHT)
	{
		if (velocityY > 0)
			velocityY += 1;
		else
			velocityY -= 1;

		velocityY *= -1;  // changing the direction of Y.
		hitWall.play();  // Playing the hit wall sound.
	}
}

sf::RectangleShape Ball::getPad() const
{
	return ball;
}

int Ball::getPosX() const
{
	return ball.getPosition().x;
}

int Ball::getPosY() const
{
	return ball.getPosition().y;
}
