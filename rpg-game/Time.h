#pragma 
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Time
{
public :
	sf::Clock clock;
	sf::Time deltatime;
	float timer = 0;

public :
	Time();
	void deltaTime(float& deltaTime);
	void updateFrame(sf::Text& frameRateText, float& deltaTime);

};

