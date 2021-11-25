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
		Player();
		virtual ~Player();

		//move player
		void move(const float xDir, const float yDir);

		// display functions
		void update();
		void render(sf::RenderTarget* target);
	private:
		// private variables
		sf::Sprite player;
		sf::Texture texture;
		float movementSpeed;
		bool isFiring;
		std::vector<Bullet> bulletVec;
		sf::Clock clock;
<<<<<<< HEAD
		Heart heart;
=======
		sf::Clock timer;
		int movementSmooth;
    	sf::Time tickRate;
>>>>>>> eb84b7f158270353b807c1499344910deed501d9
		// initialization functions
		void initTexture();
		void initSprite();
		void initBullet();

};

#endif
