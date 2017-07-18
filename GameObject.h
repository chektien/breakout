#ifndef GAMEOBJECTH
#define GAMEOBJECTH

#include <memory>
#include <SFML/Graphics.hpp>

namespace boliao {

    /************************************************************
     * @Brief The GameObject class
     * Superclass for all game objects.
     ************************************************************/
    class GameObject {
        public:
            GameObject(std::string& name);
            ~GameObject(void) {}

            void init(void);
            void run(void);
            void shut(void);

        private:
            std::string name;
    };
}

#endif
