#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>
#include "Player.h"



class game
{
private : 
	sf::RenderWindow* window;
	Player* player;


	void initWindow();
	void initPlayer();

public :
	game();
	virtual ~game();

	void run();
	void update();
	void render();
};

