#include "Skeletoin.h"
#include<iostream>
using namespace std;


Skeletoin::Skeletoin(): Hp(100)
{
}

void Skeletoin::ChangeHp(int hp)
{
    this->Hp += hp;
    healtText.setString(std::to_string(Hp));
}

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


    if (font.loadFromFile("Assets/fonts/Arial.ttf")) {
        cout << "font is loaded ";
        healtText.setFont(font);
    }
    else
    {
        cout << "font is not loaded" << endl;
    }

    healtText.setString(std::to_string(Hp));

}

void Skeletoin::Draw(sf::RenderWindow& window)
{
    if (this->Hp > 0) {
        window.draw(sprite);
        window.draw(BoundingBox);
        window.draw(healtText);
    }
}

void Skeletoin::Update(float deltaTime)
{
    BoundingBox.setPosition(sprite.getPosition());
    healtText.setPosition(this->sprite.getPosition());
}


