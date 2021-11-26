#include "Game.h"
#include "Player.h"
#include "Bullet.h"

// constructor
Game::Game() {
	this->initVariables();
	this->initWindow();
	this->initPlayer();
	this->initWalls();
}

// destructor
Game::~Game() {
	delete this->window;
	delete this->player;
}

// initialize variables
void Game::initVariables() {
	this->window = nullptr;
}

// initialize window
void Game::initWindow() {
	// create window with 1920x1080 resolution
	this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "tanks++", sf::Style::Titlebar | sf::Style::Close);
	// set 60 fps
	this->window->setFramerateLimit(60);
}

// initialize player
void Game::initPlayer() {
	//key bindings parameters go  (up, down, left, right, shoot)
	this->player = new Player(sf::Keyboard::Key::W, sf::Keyboard::Key::S, sf::Keyboard::Key::A, sf::Keyboard::Key::D, sf::Keyboard::Key::C, 400, 200);
	this->player2 = new Player(sf::Keyboard::Key::Up, sf::Keyboard::Key::Down, sf::Keyboard::Key::Left, sf::Keyboard::Key::Right, sf::Keyboard::Key::M, 1500, 1700);
}

// initialize walls
void Game::initWalls() {
	Wall* wallLeft = new Wall(50, 1080, 0, 0);
	Wall* wallRight = new Wall(50, 1080, 1870, 0);
	Wall* wallTop = new Wall(1920, 50, 0, 1030);
	Wall* wallBottom = new Wall(1920, 50, 0, 0);
	walls = { wallLeft, wallRight, wallTop, wallBottom };
}


/*
 *	running
 * 
 *	Checks if game window is still running
 * 
 *	returns:	true if running, false if not
 */
const bool Game::running() const {
	return this->window->isOpen();
}

/*
 *	pollEvents
 *
 *	Checks for event occurences
 */
void Game::pollEvents() {
	while (this->window->pollEvent(this->ev)) {
		switch (this->ev.type) {
			// window X button
			case sf::Event::Closed:
				this->window->close();
				break;
			// escape key
			case sf::Event::KeyPressed:
				if (this->ev.key.code == sf::Keyboard::Escape)
					window->close();
				break;
		}
	}
}

/*	
 *	update
 *
 *	Performs necessary game updates: time, score, etc. Continuosly call in a loop
 *	This is where all other class updates will go (Player, Bullet)
 */
void Game::update() {
	this->pollEvents();
	this->player->update();
	this->player2->update();
	if(this->player->getBounds().intersects(walls[0]->getBounds())) {
		this->player->movePos(sf::Vector2f(this->player->getSpeed(), 0));
	}

	if(this->player->getBounds().intersects(walls[1]->getBounds())) {
		this->player->movePos(sf::Vector2f(-this->player->getSpeed(), 0));
	}

	if(this->player->getBounds().intersects(walls[2]->getBounds())) {
		this->player->movePos(sf::Vector2f(0, -this->player->getSpeed()));
	}

	if(this->player->getBounds().intersects(walls[3]->getBounds())) {
		this->player->movePos(sf::Vector2f(0, this->player->getSpeed()));
	}

	// unnecessary as walls do not get updated as of now
	// for (auto& wall : this->walls) {
	//     wall->update();
	// }
}

/*
 *	render
 * 
 *	Renders the screen with updated game state. Call after update is called.
 */

void Game::drawBackground(sf::RenderTarget* target){
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("Textures/gameBackground.png");
	this->background.setTexture(backgroundTexture);
	target->draw(this->background);
}

void Game::render() {
	this->window->clear(sf::Color::White);
	// all necessary renders go here
	this->drawBackground(this->window);
	this->player->render(this->window);
	this->player2->render(this->window);
	for (auto& wall : this->walls) {
		wall->render(this->window);
	}
	this->window->display();
}
