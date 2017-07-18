#ifndef BALLH
#define BALLH

#include <memory>
#include <SFML/Graphics.hpp>

namespace boliao {

    /************************************************************
     * @Brief The Ball class
     ************************************************************/
    class Ball {
        public:
            Ball(float x, float y, float radius);
            ~Ball(void) {}

        private:
            float x_, y_, radius_;
            std::unique_ptr<sf::CircleShape> up_shape;
    };
}

#endif
