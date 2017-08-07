#ifndef BALLH
#define BALLH

#include <memory>
#include <SFML/Graphics.hpp>
#include "CONSTANTS.h"
#include "GameObject.h"

namespace boliao {

    /************************************************************
     * @Brief The Ball class
     ************************************************************/
    using shape = sf::CircleShape;

    class Ball: public GameObject {
        float x_, y_, radius_;
        sf::Vector2f vel_;
        std::shared_ptr<shape> up_shape_;

        public:
            Ball(float x, float y, float radius=BALL_RADIUS, float vel=BALL_VEL);
            ~Ball(void) {}

            void update(const float& delta_time) override;

            std::shared_ptr<shape> getShape();
            void bounceUp();

            inline float x() { return x_; }
            inline float y() { return y_; }
            inline float left() { return x_-radius_; }
            inline float right() { return x_+radius_; }
            inline float bottom() { return y_+radius_; }
            inline float top() { return y_-radius_; }
            inline void goLeft() { vel_.x = -BALL_VEL; }
            inline void goRight() { vel_.x = BALL_VEL; }
            inline void goUp() { vel_.y = -BALL_VEL; }
            inline void goDown() { vel_.y = BALL_VEL; }
    };
}

#endif
