#pragma once
#include <SFML/Graphics.hpp>
class Math
{
public :

	static sf::Vector2f NormalizedVector(sf::Vector2f vector);
	static bool DidItCollied(sf::FloatRect rec1, sf::FloatRect rec2);
};

