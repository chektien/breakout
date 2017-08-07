#include <iostream>
#include <stdio.h>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include "CONSTANTS.h"
#include "Ball.h"
#include "Game.h"
#include "Paddle.h"
#include "Brick.h"

namespace boliao {
    constexpr int windowWidth{WINDOW_WIDTH}, windowHeight{WINDOW_HEIGHT};
    constexpr int framerate{60};
    constexpr auto secsperframe = 1.f/framerate;

    Game::Game() {
        // init window ptr
        std::unique_ptr<sf::RenderWindow> aa;
        up_window = std::make_unique<sf::RenderWindow>(
                sf::VideoMode(windowWidth, windowHeight),
                "Hello fudging world!");
        up_window->setFramerateLimit(framerate);
    }

    template<class T1, class T2>
    bool Game::isCollided(T1& obj1, T2& obj2) {
        return obj1.right() >= obj2.left() && obj1.left() <= obj2.right()
            && obj1.bottom() >= obj2.top() && obj1.top() <= obj2.bottom();
    }

    void Game::run() {
        // init game objects
        Ball ball{100.f, 100.f};
        Paddle paddle{WINDOW_WIDTH/2.f, WINDOW_HEIGHT-PADDLE_HEIGHT/2.f, sf::Color::Blue};
        std::vector<Brick> bricks;
        for (auto i=1; i<=NUMBRICKS_X; ++i) {
            for (auto j=1; j<=NUMBRICKS_Y; ++j) {
                bricks.emplace_back(
                        i*(BRICK_WIDTH+BRICK_SPACING) + BRICK_OFFSET_X,
                        j*(BRICK_HEIGHT+BRICK_SPACING),
                        sf::Color::Green
                        );
            }
        }

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

            // clear window
            up_window->clear(sf::Color::Black);

            // update objects
            ball.update(secsperframe);
            paddle.update(secsperframe);
            for (auto brick: bricks) brick.update(secsperframe);

            // determine collisions
            if (isCollided<Ball, Paddle>(ball, paddle)) {
                ball.bounceUp();

                // crude implementation of physics
                if (ball.x() > paddle.x())
                    ball.goRight();
                else
                    ball.goLeft();

                //std::cout << "COLLISION between ball/paddle, ball responded." << std::endl;
            }

            // determine ball-brick collisions
            for (auto& brick: bricks) {
                if (isCollided<Ball, Brick>(ball, brick)) {
                    // mark brick as destroyed
                    brick.destroy();

                    // do collision response
                    if (ball.x() > brick.x())
                        ball.goRight();
                    else
                        ball.goLeft();

                    if (ball.y() < brick.y())
                        ball.goUp();
                    else
                        ball.goDown();

                    //std::cout << "COLLISION between ball-paddle, ball responded." << std::endl;
                }
            }

            // remove destroyed bricks
            bricks.erase(
                    std::remove_if(std::begin(bricks), std::end(bricks),
                        [](const Brick& brick){ return !brick.isActive(); }),
                    std::end(bricks));

            // draw objects
            up_window->draw(*ball.getShape());
            up_window->draw(*paddle.getShape());
            for (auto& brick: bricks) up_window->draw(*brick.getShape());

            // display all
            up_window->display();

            // update game state
            if (!ball.isActive()) up_window->close();
        }
    }
}


