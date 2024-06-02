#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>
class Bullet
{
private : 

	sf::Sprite shape;
	sf::Vector2f direction;

	float movementSpeed = 0;

public :
	
	Bullet();
	Bullet(sf::Texture* texture, float PosX, float PosY, float DirX, float DirY , float movementSpeed);
	
	virtual ~Bullet();

	const sf::FloatRect getbound() const;
	void update();
	void render(sf::RenderTarget* target);
};

