#include <iostream>
#include <stdio.h>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include "CONSTANTS.h"
#include "Brick.h"

namespace boliao {
    Brick::Brick(float x, float y, sf::Color color, float width, float height):
        RectObject(x, y, color, width, height) {
    }

    void Brick::update(const float& delta_time) {
        if (is_active_) {

        }
    }

    void Brick::destroy() {
        is_active_ = false;
    }
}
