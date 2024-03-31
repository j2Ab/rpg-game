#pragma once
#include<SFML/Graphics.hpp>

class bullet
{
public :
	float b_speed = 1.0f;
	sf::Vector2f direction;

private :
	sf::RectangleShape rectangleShape;

public :
	
	void initialize(const sf::Vector2f& position, const sf::Vector2f& target, float speed);
	void Draw(sf::RenderWindow& window);
	void Update(float deltaTime);

	inline const sf::FloatRect& GetGloableBounds(){

		return rectangleShape.getGlobalBounds();
	}
};

