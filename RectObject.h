#ifndef RECTOBJECTH
#define RECTOBJECTH

#include <memory>
#include <SFML/Graphics.hpp>
#include "CONSTANTS.h"
#include "GameObject.h"

namespace boliao {

    /************************************************************
     * @Brief The RectObject abstract class
     ************************************************************/
    using rect_shape = sf::RectangleShape;

    class RectObject: public GameObject {
        protected:
            float x_, y_, width_, height_, halfwidth_, halfheight_;
            sf::Vector2f vel_;
            std::shared_ptr<rect_shape> up_shape_;

        public:
            RectObject(float x, float y, sf::Color color, float width=PADDLE_WIDTH, float height=PADDLE_HEIGHT):
                GameObject("RectObject"), x_(x), y_(y), width_(width), height_(height),
                halfwidth_(width/2.f), halfheight_(height/2.f), vel_(PADDLE_VEL, 0.f) {
                    up_shape_ = std::make_shared<rect_shape>();
                    up_shape_->setPosition(x_, y_);
                    up_shape_->setSize({width_, height_});
                    up_shape_->setFillColor(color);
                    up_shape_->setOrigin(halfwidth_, halfheight_);
                }
            ~RectObject(void) {}

            void update(const float& delta_time) = 0;

            inline std::shared_ptr<rect_shape> getShape() { return up_shape_; }
            inline float x() { return x_; }
            inline float y() { return y_; }
            inline float left() { return x_-halfwidth_; }
            inline float right() { return x_+halfwidth_; }
            inline float bottom() { return y_+halfheight_; }
            inline float top() { return y_-halfheight_; }
    };
}

#endif
