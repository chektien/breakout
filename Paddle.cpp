#include <iostream>
#include <stdio.h>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include "CONSTANTS.h"
#include "Paddle.h"

namespace boliao {
    //using shape = sf::RectangleShape;

    Paddle::Paddle(float x, float y, sf::Color color, float width, float height):
        RectObject(x, y, color, width, height) {
    }

    void Paddle::update(const float& delta_time) {
        if (is_active_) {
            // update pos according to input
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                x_ -= vel_.x * delta_time;
                if (x_-halfwidth_ < 0) x_ = halfwidth_;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                x_ += vel_.x * delta_time;
                if (x_+halfwidth_ > WINDOW_WIDTH) x_ = WINDOW_WIDTH - halfwidth_;
            }

            // update visual position
            up_shape_->setPosition(x_, y_);

            //std::cout << "shape moved to (" << up_shape_->getPosition().x << "," << up_shape_->getPosition().x <<") with vel=(" << vel_.x << "," << vel_.y << ")" << " delta_time=" << delta_time << std::endl;
        }
    }
}
