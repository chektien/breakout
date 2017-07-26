#include <stdio.h>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Game.h"

namespace boliao {

    constexpr int windowWidth{1024}, windowHeight{720};
    constexpr int framerate{60};

    Game::Game() {
        // init window ptr
        std::unique_ptr<sf::RenderWindow> aa;
        up_window = std::make_unique<sf::RenderWindow>(
                sf::VideoMode(windowWidth, windowHeight),
                "Hello fudging world!");
        up_window->setFramerateLimit(framerate);
    }

    void Game::run() {
        // game loop
        while (up_window->isOpen()) {
            // poll for events
            sf::Event event;
            while (up_window->pollEvent(event)) {
                if (    event.type == sf::Event::Closed ||
                        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
                    up_window->close();
                }
            }

            // draw stuff
            up_window->clear(sf::Color::Black);

            // create ball
            Ball ball{100.0f, 100.0f, 50.0f};
            up_window->draw(*ball.getShape());

            // display all
            up_window->display();
        }
    }
}


