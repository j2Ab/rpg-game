#include "game.h"



game::game()
{
	this->initWindow();
	this->initPlayer();
	this->initTexture();
	this->initEnemie();
	this->initGUI();
	this->initWorldBackground();
}

game::~game()
{
	delete this->window;
	delete this->player;

	for (auto& i : texture) {
		delete i.second;
	}
	for (auto *i :this->bullets) {
		delete i;
	}
	for (auto* i : this->enemies) {
		delete i;
	}
}

void game::updatePollEvent()
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
void game::updateMovement()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->player->PlayerMove(-1.0f, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->player->PlayerMove(1.0f, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		this->player->PlayerMove(0, 1.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		this->player->PlayerMove(0, -1.0f);
	}

	if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && this->player->CanAttack()) {
		this->bullets.push_back
		(
			new Bullet(this->texture["BULLET"],
			this->player->getPos().x + this->player->getBounds().width/2.f,
			this->player->getPos().y,
			0,
			-1.0f,
			10.0f)
		);
	}
}

void game::updateEnemie()
{

	// Creating enemy at random position with use of spawan Timer we can control when this spawn thing will going to happen
	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= this->spawnTimerMax) {

		this->enemies.push_back(new enemie(rand()% this->window->getSize().x - 40.f, -150.f));
		this->spawnTimer = 0.f;
	}

	// Deleting the enemy when it surpasses the bottom of the screen
	for (size_t i = 0; i < this->enemies.size(); i++)
	{
		
		// checking collision between bullets and the enemies
		bool flag = false;
		enemies.at(i)->update();

		for (size_t k = 0; k < this->bullets.size() && !flag ; k++)
		{
			if (this->bullets[k]->getbound().intersects(this->enemies.at(i)->getBound())) {
				this->bullets.erase(this->bullets.begin() + k);
				this->enemies.erase(this->enemies.begin() + i);
				flag = true;
			}
		}

		if (!flag) {

		if (this->enemies.at(i)->getBound().top > this->window->getSize().y) {
			this->enemies.erase(this->enemies.begin() + i);
			std::cout << this->enemies.size();
		}
				
				}
	}
}

void game::renderbackground()
{
	this->window->draw(this->backgroundWorld);
}

void game::checkCollision()
{
	if (this->player->getBounds().left < 0.f) {
		this->player->setPos(0.f, this->player->getBounds().top);
	}
	else if (this->player->getBounds().left + this->player->getBounds().width >= this->window->getSize().x) {
		this->player->setPos(this->window->getSize().x - this->player->getBounds().width, this->player->getBounds().top);
	}
	if (this->player->getBounds().top < 0.f) {
		this->player->setPos(this->player->getBounds().left, 0.f);
	}
	else if (this->player->getBounds().top + this->player->getBounds().height >= this->window->getSize().y) {
		this->player->setPos(this->player->getBounds().left, this->window->getSize().y - this->player->getBounds().height);
	}

}

void game::renderGui()
{
	this->window->draw(this->pointText);

}

void game::updateBullet()
{
	unsigned counter = 0;
	for (auto* i : this->bullets) {
		i->update();


		//bullet is culling at the top of the screen
		if (i->getbound().top + i->getbound().height < 0.f) {


			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
			std::cout << this->bullets.size() << std::endl;
		}

		++counter;
	}

}
// Private Fucitons

void game::initTexture()
{
	this->texture["BULLET"] = new sf::Texture();
	if(!this->texture["BULLET"]->loadFromFile("Assets/player/texture/bullet.png")) {
		std::cout << "Bullet texture is not loaded" << "\n";
	}
}

void game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Swagii", sf::Style::Fullscreen);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

void game::initPlayer()
{

	this->player = new Player();
	this->player->SetPos(this->window->getSize().x  / 2.f - this->player->getBounds().width / 2, this->window->getSize().y - this->player->getBounds().height);
}

void game::initEnemie()
{
	this->spawnTimerMax = 20.0f;
	this->spawnTimer = this->spawnTimerMax;
	
}

void game::initGUI()
{
	std::cout << "Font Loaded" << std::endl;
	if (!this->font.loadFromFile("Assets/fonts/arial.ttf")) {
		std::cout << "GAME::Font not loaded" << std::endl;
	}
	this->pointText.setFont(this->font);
	this->pointText.setFillColor(sf::Color::White);
	this->pointText.setCharacterSize(15);
	this->pointText.setString("A Font");
}

void game::initWorldBackground()
{
	if (!this->backgorundTexture.loadFromFile("Assets/player/texture/bg.jpg")) {
		std::cout << "Cant load BAckgorund" << std::endl;
	}
	this->backgroundWorld.setTexture(this->backgorundTexture);
	this->backgroundWorld.setScale(0.35f, 0.35f);
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

	this->player->update();
	this->updatePollEvent();
	this->updateMovement();
	this->checkCollision();
	this->updateBullet();
	this->updateEnemie();
}

void game::render()
{
	this->window->clear();

	// Draw it 
	this->renderbackground();
	this->player->render(*this->window);

	for (auto* i : this->bullets) {
		i->render(this->window);
	}

	for (auto* enemy : this->enemies) {
		enemy->render(this->window);
	}
	this->renderGui();
	this->window->display();
}
