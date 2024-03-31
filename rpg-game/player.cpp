#include "player.h"
#include "Skeletoin.h"
#include "Math.h"
#include "bullet.h"
#include <iostream>


using namespace std;

Player::Player() : fireRateTimer(1), maxFire(50) {
		
}

void Player::load() {
	if (texture.loadFromFile("Assets/player/texture/player.png")) {

	sprite.setTexture(texture);
	cout << "player Texture is loaded";
	}
	else
	{
		cout << "player Texture is not loaded";
	}

	sprite.setTextureRect(sf::IntRect(1 * size.x, 1 * size.y, size.x, size.y));
	sprite.setScale(sf::Vector2f(scale.x, scale.y));
	sprite.setPosition(sf::Vector2f(500, 500));
}

void Player::initialize() {

	BoundingBox.setFillColor(sf::Color::Transparent);
	BoundingBox.setOutlineThickness(1);
	BoundingBox.setOutlineColor(sf::Color::Red);
	BoundingBox.setSize(sf::Vector2f(size.x, size.y));
	BoundingBox.setScale(sf::Vector2f(scale.x, scale.y));


}

void Player::Draw(sf::RenderWindow& window){
	window.draw(sprite);
	window.draw(BoundingBox);
	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i].Draw(window);
	}

}
void Player::Update(Skeletoin& Skeletoin, float deltaTime,sf::Vector2f mousePosition) {

	sf::Vector2f position = sprite.getPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		sprite.setPosition(position + sf::Vector2f(-1, 0) * p_speed * deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		sprite.setPosition(position + sf::Vector2f(1, 0) * p_speed * deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		sprite.setPosition(position + sf::Vector2f(0, -1) * p_speed * deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
	    sprite.setPosition(position + sf::Vector2f(0, 1) * p_speed * deltaTime);
	}

	fireRateTimer += deltaTime;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && fireRateTimer >= maxFire) {

		bullets.push_back(bullet());
		int i = bullets.size() - 1;
		bullets[i].initialize(sprite.getPosition(), mousePosition ,2.0f);

		fireRateTimer = 0;
	}


	for (size_t i = 0; i < bullets.size(); i++)
	{

		bullets[i].Update(deltaTime);

		if (Math::DidItCollied(bullets[i].GetGloableBounds(), Skeletoin.sprite.getGlobalBounds())) {
			
			Skeletoin.ChangeHp(-10);

			bullets.erase(bullets.begin() + i);
			cout << "skeleton Health " << Skeletoin.Hp << endl;
		}
		
	}


	BoundingBox.setPosition(sprite.getPosition());

	if (Math::DidItCollied(sprite.getGlobalBounds(), Skeletoin.sprite.getGlobalBounds())) {

		std::cout << "Collision" << endl;
	}
}