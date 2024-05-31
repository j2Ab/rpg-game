#include "Player.h"
#include<iostream>

void Player::initSprite()
{
	this->sprite.setTexture(this->texture);

}

void Player::initTexture()
{
	if (!this->texture.loadFromFile("Assets/player/texture")) {
		std::cout << "initTexture Can't load the texture";
	}
}

Player::Player()
{
	this->initTexture();
	this->initSprite();

}

Player::~Player()
{

}

void Player::update()
{
}

void Player::render(sf::RenderTarget& target) 
{
	target.draw(this->sprite);
}
