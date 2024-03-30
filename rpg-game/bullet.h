#pragma once
#include<SFML/Graphics.hpp>

class bullet
{
public :
	

private :
	std::vector <sf::RectangleShape> bullets;

public :
	
	bullet(){
	}

	void initialize();
	void load();
	void Draw(sf::RenderWindow& window);
	void Update();
};

