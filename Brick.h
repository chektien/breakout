#ifndef BRICKH
#define BRICKH

#include <memory>
#include <SFML/Graphics.hpp>
#include "CONSTANTS.h"
#include "RectObject.h"

namespace boliao {

    /************************************************************
     * @Brief The Brick class
     ************************************************************/
    class Brick: public RectObject {

        public:
            Brick(float x, float y, sf::Color color, float width=BRICK_WIDTH, float height=BRICK_HEIGHT);
            ~Brick(void) {}

            void update(const float& delta_time) override;
            void destroy();
    };
}

#endif
