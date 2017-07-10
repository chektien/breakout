#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Game.h"

namespace boliao {

    constexpr int windowWidth{1024}, windowHeight{720}
    
    Game::Game() {
        // change window into pointer
        window(sf::VideoMode(windowWidth, windowHeight), "Hello fudging world!");
        window.setFrameLimit(60);
    }
    
    Game::run() {
        while (true) {
            window.clear(sf::Color::black);

            if (sf::keyboard::isKeyPressed(Keyboard::Key::Escape)) {
                break;
            }

            sf::CircleShape shape{100.f};
            shape.setFillColor(sf::Color::Green);

            window.draw(shape);

            window.display();
        }
    }
}


