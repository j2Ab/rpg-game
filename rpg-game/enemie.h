#pragma once
#include<SFML/Graphics.hpp>

class enemie
{
private :
		
	sf::Sprite shape;
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
	enemie(float PosX, float PosY, sf::Texture* texture);
	~enemie();

	const sf::FloatRect getBound() const;
	float randNumber();
	void setRotaion(float rot);
	float getRota();
	void getPoints(int& p);
	void render(sf::RenderTarget* target);
	void update();
};

