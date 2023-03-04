#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


// The width and the height of the game.
#define WIDTH 1280
#define HEIGHT 800
#define FPS 60

/*
* This Entity class will have the basics information for all any object in the game.
* Any other object will derive from the Entitry class.
* The Entity class will have the position and the velocity of the object.
* Also will have the shape(Texture).
*/
class Entity
{
protected:
	int posX, posY, velocityX, velocityY;
	sf::Texture tex;

public:
	Entity(int posX, int posY, int velocityX, int velocityY);

	std::pair<int, int> getVelocity() const;
	void setVelocity(int velX, int velY);
};


class Player : public Entity
{
public:
	Player(int posX, int posY, int velocityX, int velocityY, char color);

	void move();

	sf::RectangleShape getPad() const;
	int getPosX() const;
	int getPosY() const;
	void setPos(int posX, int posY);

private:
	sf::RectangleShape pad;
};

/*
* The Ball class will derive from the Entitry class.
* It will have the sounds for the collision.
*/
class Ball : public Entity
{
public:
	Ball(int posX, int posY, int velocityX, int velocityY);
	
	void move(Player& player1, Player& player2);

	sf::RectangleShape getPad() const;
	int getPosX() const;
	int getPosY() const;

private:
	void handleCollision(Player& player1, Player& player2);
	void handleWinning(Player& player1, Player& player2);
	void handleHittingWall();

private:
	sf::RectangleShape ball;
	
	sf::SoundBuffer buff_hitPad;
	sf::SoundBuffer buff_hitWall;
	sf::SoundBuffer buff_Score;

	sf::Sound hitPad;
	sf::Sound hitWall;
	sf::Sound Score;
};

