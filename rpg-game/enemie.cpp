#include "enemie.h"

void enemie::initVariables()
{
	this->hp  = 0;
	this->hpMax = 10;
	this->damge = 1;
	this->points = 0;
	this->speed = 2.0f;
}

void enemie::initShapes()
{

}


// constructor
enemie::enemie(float PosX, float PosY, sf::Texture* texture)
{
	this->shape.setTexture(*texture);
	this->initShapes();
	this->initVariables();
	this->shape.setPosition(PosX, PosY);
	this->shape.setRotation(rand() % 180);
	auto store = this->randNumber();
	this->shape.setScale(store, store);

}

enemie::~enemie()
{
}

const sf::FloatRect enemie::getBound() const
{
	return this->shape.getGlobalBounds();
}

float enemie::randNumber()
{
	auto getRandomFloat = [](float min, float max) {
		return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / (max - min));
		};
	return getRandomFloat(0.4 , 0.1);
}

void enemie::setRotaion(float rot)
{
	this->shape.setRotation(rot);
}

float enemie::getRota()
{
	return this->shape.getRotation();
}

void enemie::getPoints(int& p)
{
}

void enemie::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

void enemie::update()
{
	this->shape.move(0, this->speed);
}
