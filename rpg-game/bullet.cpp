#include "bullet.h"
#include "Math.h"
#include <iostream>
#include "player.h"


void bullet::initialize(const sf::Vector2f& position ,const sf::Vector2f& target, float speed)
{
	this->b_speed = speed;
	rectangleShape.setSize(sf::Vector2f(30, 25));
	rectangleShape.setPosition(position);
	this->direction =Math::NormalizedVector( target - position);
}

void bullet::Draw(sf::RenderWindow& window)
{
	window.draw(rectangleShape);
}

void bullet::Update(float deltaTime)
{
	rectangleShape.setPosition(rectangleShape.getPosition() + direction * b_speed * deltaTime);
}
