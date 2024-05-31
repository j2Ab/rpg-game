#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

class Player
{
private :

	sf::Sprite sprite;
	sf::Texture texture;


	void initSprite();
	void initTexture();

public :

	Player();
	virtual ~Player();

	void update();
	void render(sf::RenderTarget& target) ;

};

