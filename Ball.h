#ifndef BALLH
#define BALLH

#include <memory>
#include <SFML/Graphics.hpp>
#include "GameObject.h"

namespace boliao {

    /************************************************************
     * @Brief The Ball class
     ************************************************************/
    class Ball: public GameObject {
        float x_, y_, radius_;
        std::shared_ptr<sf::CircleShape> up_shape;

        public:
            Ball(float x, float y, float radius);
            ~Ball(void) {}

            std::shared_ptr<sf::CircleShape> getShape();
    };
}

#endif
