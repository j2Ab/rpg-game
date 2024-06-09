#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>
#include<map>
#include<vector>
#include "Player.h"
#include "Bullet.h"
#include "enemie.h"



class game
{
private : 
	sf::RenderWindow* window;

	// BackGround World

	sf::Sprite backgroundWorld;
	sf::Texture backgorundTexture;


	// GUI 
	
	sf::Font font;
	sf::Text pointText;

	//Player stuff
	Player* player;

	// Enemy stuff
	std::vector<enemie*> enemies;
	std::map<std::string, sf::Texture*> Etexture;

	// Time spawn controlers
	float spawnTimer;
	float spawnTimerMax;
	

	// Bullet stuff
	std::map<std::string, sf::Texture*> texture;
	std::vector<Bullet*> bullets;


	int p;


	bool autoPlay;

	
	void initVariable();
	void initTexture();
	void initWindow();
	void initPlayer();
	void initEnemie();
	void initGUI();
	void initWorldBackground();

public :
	game();
	virtual ~game();

	std::string randomStrings();

	void renderbackground();
	void checkCollision();
	void renderGui();
	void updateGUI();
	void updateBullet();
	void updatePollEvent();
	void updateMovement();
	void updateEnemie();
	void run();
	void update();
	void render();
};

