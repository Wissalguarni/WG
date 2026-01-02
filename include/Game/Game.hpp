#ifndef GAME_H
#define GAME_H
//Game is abstarct
class Game{
    public:
          virtual void start()=0; // Starts the game 
          virtual void inprogress()=0 ; //the game is in progress
          virtual void end()=0  ; // Ends the game 
          virtual ~Game(){};//Destructor


};
#endif