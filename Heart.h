#ifndef HEART_H
#define HEART_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <math.h>

class Heart
{
    public:
        Heart(sf::Vector2f, sf::Color);
        virtual ~Heart();
        void render(sf::RenderTarget* target);
    private:
        sf::RectangleShape heart;
        sf::Texture texture;
        void initTexture();
        void initHealth(sf::Vector2f, sf::Color);
};

#endif