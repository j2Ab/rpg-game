#include "Bullet.h"

Bullet::Bullet()
{
	
}

Bullet::Bullet(sf::Texture* texture, float PosX, float PosY, float DirX, float DirY, float movementSpeed)
{
	this->shape.setTexture(*texture);
	this->direction.x = DirX;
	this->direction.y = DirY;
	this->movementSpeed = movementSpeed;
	this->shape.setOrigin(sf::Vector2f(this->shape.getGlobalBounds().width / 2, this->shape.getGlobalBounds().height / 2));
	this->shape.setPosition(PosX, PosY);
	this->shape.setScale(0.2f, 0.2f);
}

Bullet::~Bullet()
{
}

const sf::FloatRect Bullet::getbound() const
{
	return this->shape.getGlobalBounds();
}

void Bullet::update()
{
	this->shape.move(this->movementSpeed * this->direction);
}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
