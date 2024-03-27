#include <SFML/Graphics.hpp>
#include<iostream>
#include<math.h>
using namespace std;

sf::Vector2f NormalizedVector(sf::Vector2f vector) {

   double Magintude = sqrt(vector.x * vector.x + vector.y * vector.y);

   sf::Vector2f Normalized;

   Normalized.x = vector.x / Magintude;
   Normalized.y = vector.y / Magintude;

   return Normalized;
}



int main()
{

    sf::ContextSettings setting;
    setting.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!" , sf::Style::Default | sf::Style::Fullscreen , setting);

//-------------------------------------Enemy player-----------------------------------------
    sf::Texture skeletonTexture;
    sf::Sprite skeletonSprite;

    if (skeletonTexture.loadFromFile("Assets/player/texture/player.png")) {
        cout << "enemy texture is loaded" << endl;
        skeletonSprite.setTexture(skeletonTexture);
    }
    else
    {
        cout << "enemy textures is not loaded";
    }
    int imageSize = 64;

    int index_x1 = 3 * 64;
    int index_y1 = 3 * 64;

    skeletonSprite.setTextureRect(sf::IntRect(index_x1,index_y1,imageSize,imageSize));
    skeletonSprite.setScale(sf::Vector2f(3, 3));
    skeletonSprite.setPosition(sf::Vector2f(300, 250));


    //-------------------------------------Enemy player-----------------------------------------


    //-------------------------------------Character Player----------------------------------

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

    playerSprite.setTextureRect(sf::IntRect(index_x,index_y,imageSize,imageSize));
    playerSprite.setScale(sf::Vector2f(3,3));
    playerSprite.setPosition(sf::Vector2f(1650, 800));
    

//-------------------------------------Character Player----------------------------------

//------------------------------------------bullet-----------------------------------

    vector <sf::RectangleShape > bullet;
    

    float b_speed = 0.5f;

//------------------------------------------bullet-----------------------------------


    // Finding the loaiton of the enemy  T is enemy    C is bullet loaciton

    //   Formula :           D = T - C

    //sf::Vector2f  b_direction = skeletonSprite.getPosition() - bullet.getPosition();

    // Normalizing the direction by the fuction
    
   // b_direction = NormalizedVector(b_direction);

//--------------------------------------game loop----------------------------------------

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
//--------------------------------game loop----------------------------------------


        // updateing the postion of the bullet


        //    Now we need to update the Postion of the bullet every frame 
        //          D + BulletPosition

       // sf::Vector2f  bulletPosition = bullet.getPosition();
       // bullet.setPosition(bulletPosition + b_direction * b_speed);


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
    
//--------------------------------Movment-----------------------------------------------------------------------------




//--------------------------------generationn bullets-----------------------------------------------------------------------
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

            bullet.push_back(sf::RectangleShape(sf::Vector2f(20, 5)));
                                                                                //sf::RectangleShape bullet(sf::Vector2f(20, 5));   // parameters are the size of the bullet
            bullet[bullet.size() - 1].setPosition(playerSprite.getPosition());
        }                                                                        //bullet.setPosition(sf::Vector2f(playerSprite.getPosition()))

                                                                                 
        for (size_t i = 0; i < bullet.size(); i++)
        {

            sf::Vector2f D_bullet = skeletonSprite.getPosition() - bullet[i].getPosition();
            D_bullet = NormalizedVector(D_bullet);
            bullet[i].setPosition(bullet[i].getPosition() + D_bullet * b_speed);

        }
                                                                                 

//--------------------------------generationn bullets-----------------------------------------------------------------------

 //--------------------------------update----------------------------------------
        window.clear(sf::Color::Black);

        window.draw(playerSprite);
        
        window.draw(skeletonSprite);
        for (size_t i = 0; i < bullet.size(); i++)
        {
            window.draw(bullet[i]);
        }

        window.display();
    }
 //--------------------------------update----------------------------------------

    return 0;
}