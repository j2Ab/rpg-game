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

	// GUI 
	
	sf::Font font;
	sf::Text pointText;

	//Player stuff
	Player* player;

	// Enemy stuff
	std::vector<enemie*> enemies;
	float spawnTimer;
	float spawnTimerMax;
	

	// Bullet stuff
	std::map<std::string, sf::Texture*> texture;
	std::vector<Bullet*> bullets;


	void initTexture();
	void initWindow();
	void initPlayer();
	void initEnemie();
	void initGUI();

public :
	game();
	virtual ~game();


	
	void renderGui();
	void updateBullet();
	void updatePollEvent();
	void updateMovement();
	void updateEnemie();
	void run();
	void update();
	void render();
};
