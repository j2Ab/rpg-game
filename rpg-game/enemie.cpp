#include "enemie.h"

void enemie::initVariables()
{
	this->hp  = 0;
	this->hpMax = 10;
	this->damge = 1;
	this->points = 5;
	this->type = 0;
	this->speed = 4.0f;
}

void enemie::initShapes()
{
	this->shape.setRadius(rand() % +50);
	this->shape.setPointCount(rand() % 20 + 3);
	this->shape.setFillColor(sf::Color(rand() % 255 + 1, rand()% 255 + 1, rand()% 255 + 1,255));

}

enemie::enemie()
{
}

enemie::enemie(float PosX, float PosY)
{
	this->initShapes();
	this->initVariables();
	this->shape.setPosition(PosX, PosY);
}

enemie::~enemie()
{
}

const sf::FloatRect enemie::getBound() const
{
	return this->shape.getGlobalBounds();
}

void enemie::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

void enemie::update()
{
	this->shape.setScale(2.f, 2.f);
	this->shape.move(0, this->speed);
}
