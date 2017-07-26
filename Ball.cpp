#include <stdio.h>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include "CONSTANTS.h"
#include "Ball.h"

namespace boliao {
    Ball::Ball(float x, float y, float radius=BALL_RADIUS)
        : GameObject("Ball"), x_(x), y_(y), radius_(radius) {
        up_shape = std::make_shared<sf::CircleShape>();
        up_shape->setPosition(x_, y_);
        up_shape->setRadius(radius_);
        up_shape->setFillColor(sf::Color::Red);
        up_shape->setOrigin(radius_, radius_);
    }

    std::shared_ptr<sf::CircleShape> Ball::getShape() {
        //return std::weak_ptr<sf::CircleShape>{up_shape};
        return up_shape;
    }
}
