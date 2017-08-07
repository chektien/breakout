#ifndef GAMEOBJECTH
#define GAMEOBJECTH

#include <memory>
#include <SFML/Graphics.hpp>

namespace boliao {

    /************************************************************
     * @Brief The GameObject abstract class
     * Superclass for all game objects.
     * @TODO component-based logic
     ************************************************************/
    class GameObject {
        public:
            GameObject(const std::string& name): name_(name) {}
            ~GameObject(void) {}

            virtual void init(void) {};
            virtual void update(const float& delta_time) = 0;
            virtual void shut(void) {};

            inline bool isActive() const { return is_active_; }
        protected:
            std::string name_;
            bool is_active_ = true;

    };
}

#endif
