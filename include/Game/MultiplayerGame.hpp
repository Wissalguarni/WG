#ifndef MULTIPLAYERGAME_H
#define MULTIPLAYERGAME_H

#include "Game.hpp"
class MultiplayerGame: public Game {
    private:
       bool ledON;
       bool gamefinished;
    public:
       MultiplayerGame();
       void start() override;
       void inprogress() override;
       void end() override ;
};
#endif