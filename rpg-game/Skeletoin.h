#pragma once
#include <SFML/Graphics.hpp>

class Skeletoin
{

private:

	sf::Texture texture;

public:
	sf::Sprite sprite;
	int Hp = 0;

public :
	sf::RectangleShape BoundingBox;
public : 
	sf::Vector2f size = sf::Vector2f(64, 64);
	sf::Vector2f scale = sf::Vector2f(3, 3);

	sf::Text healtText;
	sf::Font font;
public:
	Skeletoin();

	void ChangeHp(int hp);
	void initialize();
	void load();
	void Draw(sf::RenderWindow& window);
	void Update(float deltaTime);
};

