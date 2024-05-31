#include "game.h"



game::game()
{
	this->initWindow();
	this->initPlayer();
}

game::~game()
{
	delete this->window;
	delete this->player;
}
// Private Fucitons
void game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Swagii", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

void game::initPlayer()
{
	player = new Player();

}


// Function 
void game::run()
{
	while (window->isOpen())
	{
	update();
	render();
	}
}

void game::update()
{
	sf::Event e;
	while (window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed) {
			this->window->close();
		}
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape) {
			this->window->close();
		}
	}
}

void game::render()
{
	this->window->clear();

	// Draw it 
	this->player->render(*this->window) ;

	this->window->display();
}
