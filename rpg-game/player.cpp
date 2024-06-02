#include "Player.h"
#include<iostream>

void Player::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.scale(0.1f, 0.1f);
}

void Player::initVariables()
{
	this->movementSpeed = 4.0f;
	this->bulletCoolDownMax = 10.f;
	this->bulletCoolDown = this->bulletCoolDownMax;

}

void Player::initTexture()
{
	if (!this->texture.loadFromFile("Assets/player/texture/ship.png")) {
		std::cout << "initTexture Can't load the texture";
	}
}

Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();

}

Player::~Player()
{

}

const sf::FloatRect Player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

sf::Vector2f Player::getPos()
{
	return this->sprite.getPosition();
}

void Player::setPos(float x, float y)
{
	this->sprite.setPosition(x, y);
}

void Player::PlayerMove(float DirX, float DirY)
{
	this->sprite.move(this->movementSpeed * DirX, this->movementSpeed * DirY);
}

void Player::updateAttack()
{
	if (this->bulletCoolDown < this->bulletCoolDownMax) {
		this->bulletCoolDown += 0.5f;
	}
}

bool Player::CanAttack()
{
	if (this->bulletCoolDown >= this->bulletCoolDownMax) {
		this->bulletCoolDown = 0.5f;
		return true;
	}
	else {
		return false;
	}
}

void Player::SetPos(float PosX, float PosY)
{
	this->sprite.setPosition(PosX , PosY);

}

void Player::update()
{
	this->updateAttack();
}

void Player::render(sf::RenderTarget& target) 
{
	target.draw(this->sprite);
}
