#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

/*
* This Entity class will have the basics information for all any object in the game.
* Any other object will derive from the Entitry class.
* The Entity class will have the position and the velocity of the object.
* Also will have the shape(Texture).
*/
class Entity
{
public:
	Entity(int posX, int posY, int velocityX, int velocityY);

	void move();
public:
	int posX, posY, velocityX, velocityY;
	sf::Texture tex;
};


class Player : public Entity
{
public:
	Player(int posX, int posY, int velocityX, int velocityY, char color);

	sf::RectangleShape getPad() const;

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
	
	sf::RectangleShape getPad() const;

private:
	sf::RectangleShape ball;
	
	sf::SoundBuffer buff_hitPad;
	sf::SoundBuffer buff_hitWall;
	sf::SoundBuffer buff_Score;

	sf::Sound hitPad;
	sf::Sound hitWall;
	sf::Sound Score;
};

