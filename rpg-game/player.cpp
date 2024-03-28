#include "player.h"
#include "Skeletoin.h"
#include "Math.h"
#include <iostream>


using namespace std;

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

}
void Player::Update(Skeletoin Skeletoin, float deltaTime) {

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

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		bullet.push_back(sf::RectangleShape(sf::Vector2f(30, 25)));
		bullet[bullet.size() - 1].setPosition(sprite.getPosition());
	}


	for (size_t i = 0; i < bullet.size(); i++)
	{
		sf::Vector2f D_bullet = Skeletoin.sprite.getPosition() - bullet[i].getPosition();
		D_bullet = Math::NormalizedVector(D_bullet);
		bullet[i].setPosition(bullet[i].getPosition() + D_bullet * b_speed * deltaTime);
	}

	BoundingBox.setPosition(sprite.getPosition());


	if (Math::DidItCollied(sprite.getGlobalBounds(), Skeletoin.sprite.getGlobalBounds())) {

		std::cout << "Collision" << endl;
	}
}