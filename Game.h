#ifndef GAMEH
#define GAMEH

#include <memory>
#include <SFML/Graphics.hpp>

namespace boliao {
    
    /************************************************************
     * @Brief The Game class
     * Container for the game.
     ************************************************************/
    class Game {
        public:
            Game();
            ~Game(void) {}

            void init(void);
            void run(void);
            void shut(void);
        
        private:
            std::unique_ptr<sf::RenderWindow> up_window;
    };
}

#endif
