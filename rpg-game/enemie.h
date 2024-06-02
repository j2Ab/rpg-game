#pragma once
#include<SFML/Graphics.hpp>

class enemie
{
private :
		
	sf::CircleShape shape;
	int hp;
	int hpMax;
	int damge;
	int points;
	int type;
	float speed;


	void initVariables();
	void initShapes();
	

public : 
	enemie();
	enemie(float PosX, float PosY);
	~enemie();

	const sf::FloatRect getBound() const;

	void render(sf::RenderTarget* target);
	void update();
};

