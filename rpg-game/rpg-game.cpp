#include "player.h"
#include "Skeletoin.h"
#include "Math.h"
#include<iostream>

using namespace std;

int main()
{

    sf::ContextSettings setting;
    setting.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!" , sf::Style::Default , setting);
    window.setFramerateLimit(60);

    sf::Clock clock;
    sf::Time deltatime;

    sf::Text frameRateText;
    sf::Font font;

    if (font.loadFromFile("Assets/fonts/Arial.ttf")) {
        cout << "font is loaded ";
        frameRateText.setFont(font);
    }
    else
    {
        cout << "font is not loaded" << endl;
    }

    Player player;
    Skeletoin skeletoin;


    skeletoin.initialize();
    player.initialize();


    skeletoin.load();
    player.load();


    
//--------------------------------------game loop----------------------------------------

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

    
        deltatime = clock.getElapsedTime();
        clock.restart();
        float deltaTime = deltatime.asMilliseconds();
        
        player.Update(skeletoin, deltaTime);
        skeletoin.Update(deltaTime);
        // Frame Rates 
        //"Frame : " << 1000.0f / deltaTime
         frameRateText.setString("Frame Rates :  ");
 //--------------------------------update----------------------------------------
        window.clear(sf::Color::Black);
        
        skeletoin.Draw(window);
        player.Draw(window);

        for (size_t i = 0; i < player.bullet.size(); i++)
        {
            window.draw(player.bullet[i]);
        }

        window.display();
    }
 //--------------------------------update----------------------------------------

    return 0;
}