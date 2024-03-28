#include "Skeletoin.h"
#include<iostream>
using namespace std;
void Skeletoin::initialize()
{
    BoundingBox.setFillColor(sf::Color::Transparent);
    BoundingBox.setOutlineThickness(1);
    BoundingBox.setOutlineColor(sf::Color::Blue);
    BoundingBox.setSize(sf::Vector2f(size.x, size.y));
    BoundingBox.setScale(sf::Vector2f(scale.x, scale.y));
}

void Skeletoin::load()
{
    if (texture.loadFromFile("Assets/player/texture/player.png")) {
        cout << "enemy texture is loaded" << endl;
        sprite.setTexture(texture);
    }
    else
    {
        cout << "enemy textures is not loaded";
    }
   
    sprite.setTextureRect(sf::IntRect(scale.x * size.x, scale.y * size.y, size.x, size.y));
    sprite.setScale(sf::Vector2f(scale.x, scale.y));

    sprite.setPosition(sf::Vector2f(300, 250));
}

void Skeletoin::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    window.draw(BoundingBox);
}

void Skeletoin::Update(float deltaTime)
{
    BoundingBox.setPosition(sprite.getPosition());
}
