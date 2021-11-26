#ifndef PLAYER_H
#define PLAYER_H

#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <math.h>
#include "Bullet.h"
#include "Heart.h"

/*
 *	Player
 *
 *	Player class. Movement, controls, and textures will be handled here
 */
class Player {
	public:
		// constructor / destructor
		Player(sf::Keyboard::Key upKey, sf::Keyboard::Key downKey, sf::Keyboard::Key leftKey, sf::Keyboard::Key rightKey, sf::Keyboard::Key shootKey);
		virtual ~Player();

		//move player
		void move(const float xDir, const float yDir);
		void updateInput();
		// display functions
		void update();
		void render(sf::RenderTarget* target);
	private:
		// private variables
		sf::Keyboard::Key upKey;
		sf::Keyboard::Key downKey; 
		sf::Keyboard::Key leftKey;
		sf::Keyboard::Key rightKey; 
		sf::Keyboard::Key shootKey;
		sf::Sprite player;
		sf::Texture texture;
		float movementSpeed;
		bool isFiring;
		std::vector<Bullet*> bulletVec;
		sf::Clock clock;
		std::vector<Heart*> heartVec;
		int health;
		sf::Clock timer;
		int movementSmooth;
    	sf::Time tickRate;
		// initialization functions
		void initTexture();
		void initSprite();
		void initBullet();

};

#endif
