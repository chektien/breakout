#include <iostream>
#include <stdio.h>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include "CONSTANTS.h"
#include "Ball.h"

namespace boliao {
    using shape = sf::CircleShape;

    Ball::Ball(float x, float y, float radius, float vel)
        : GameObject("Ball"), x_(x), y_(y), radius_(radius), vel_(vel, vel) {
        up_shape_ = std::make_shared<sf::CircleShape>();
        up_shape_->setPosition(x_, y_);
        up_shape_->setRadius(radius_);
        up_shape_->setFillColor(sf::Color::Red);
        up_shape_->setOrigin(radius_, radius_);
    }

    std::shared_ptr<shape> Ball::getShape() {
        return up_shape_;
    }

    void Ball::bounceUp() {
        vel_.y = -vel_.y;
    }

    void Ball::update(const float& delta_time) {
        if (is_active_) {
            // collision response
            if ( (x_-radius_) < 0 )
                vel_.x = -vel_.x;
            if ( (x_+radius_) > WINDOW_WIDTH )
                vel_.x = -vel_.x;
            if ( (y_-radius_) < 0 )
                vel_.y = -vel_.y;

            // check collision with paddle
            if ( (y_+radius_) > WINDOW_HEIGHT ) {
                is_active_ = false;
                std::cout << "BALL FELL BELOW, YOU LOSE" << std::endl;
            }

            // update position
            x_ += vel_.x * delta_time;
            y_ += vel_.y * delta_time;
            up_shape_->setPosition(x_, y_);

            //std::cout << "shape moved to (" << up_shape_->getPosition().x << "," << up_shape_->getPosition().x <<") with vel=(" << vel_.x << "," << vel_.y << ")" << " delta_time=" << delta_time << std::endl;
        }
    }
}
