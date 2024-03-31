#pragma once
#include <SFML/Graphics.hpp>
#include "Skeletoin.h"
#include "Bullet.h"


class Player
{
private :
	sf::Texture texture;

public :
	sf::Sprite sprite;
	float p_speed = 1.0f;
	float fireRateTimer;
	float maxFire;

public : 
	sf::RectangleShape BoundingBox;
	std::vector<bullet> bullets;

public :
	sf::Vector2f size = sf::Vector2f(64, 64);
	sf::Vector2f scale = sf::Vector2f(3, 3);

public :

	Player();

	void initialize();
	void load();
	void Draw(sf::RenderWindow& window);
	void Update(Skeletoin& Skeletoin, float deltaTime, sf::Vector2f mousePosition);
};

