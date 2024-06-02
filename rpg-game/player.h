#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

class Player
{
private :

	sf::Sprite sprite;
	sf::Texture texture;
	float movementSpeed;
	float bulletCoolDown;
	float bulletCoolDownMax;


	void initSprite();
	void initVariables();
	void initTexture();

public :

	Player();
	virtual ~Player();
	
	const sf::FloatRect getBounds() const ;
	sf::Vector2f getPos();

	//Modifirers 
	void setPos(float x , float y);


	void PlayerMove(float DirX , float DirY);
	void updateAttack();
	bool CanAttack();
	void SetPos(float PosX, float PosY);
	void update();
	void render(sf::RenderTarget& target) ;

};

