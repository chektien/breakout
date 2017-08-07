#ifndef PADDLEH
#define PADDLEH

#include <memory>
#include <SFML/Graphics.hpp>
#include "CONSTANTS.h"
#include "RectObject.h"

namespace boliao {

    /************************************************************
     * @Brief The Paddle class
     ************************************************************/
    using rect_shape = sf::RectangleShape;

    class Paddle: public RectObject {

        public:
            Paddle(float x, float y, sf::Color color, float width=PADDLE_WIDTH, float height=PADDLE_HEIGHT);
            ~Paddle(void) {}

            void update(const float& delta_time) override;
    };
}

#endif
