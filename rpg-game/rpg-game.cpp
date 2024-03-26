#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;

int main()
{

    sf::ContextSettings setting;
    setting.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!" , sf::Style::Default , setting);

    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    if (playerTexture.loadFromFile("Assets/player/texture/player.png")) {
        cout << "texture is loaded";
        playerSprite.setTexture(playerTexture);
    }else
    {
        cout << "Texture is not loaded";
    }

    // indexes of the texture 
    int index_x = 6 * 64;
    int index_y = 2 * 64;

    playerSprite.setTextureRect(sf::IntRect(index_x,index_y,64,64));
    playerSprite.setScale(sf::Vector2f(3,3));


//--------------------------------game loop----------------------------------------

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        }
//--------------------------------game loop----------------------------------------

//--------------------------------Movment----------------------------------------

     
sf::Vector2f position = playerSprite.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            playerSprite.setPosition(position + sf::Vector2f(-1, 0));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            playerSprite.setPosition(position + sf::Vector2f(1, 0));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            playerSprite.setPosition(position + sf::Vector2f(0, -1));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            playerSprite.setPosition(position + sf::Vector2f(0, 1));
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            playerSprite.setPosition(position + sf::Vector2f(-1, 0));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            playerSprite.setPosition(position + sf::Vector2f(1, 0));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            playerSprite.setPosition(position + sf::Vector2f(0, -1));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            playerSprite.setPosition(position + sf::Vector2f(0, 1));
        }

//--------------------------------Movment----------------------------------------

 //--------------------------------update----------------------------------------
        window.clear(sf::Color::Black);

        window.draw(playerSprite);

        window.display();
    }
 //--------------------------------update----------------------------------------

    return 0;
}