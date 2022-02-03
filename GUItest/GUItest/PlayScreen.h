//
//  PlayScreen.h
//  Chloe1
//
//  Created by Chloe Brydon on 2020-11-29.
//

#pragma once
#ifndef PlayScreen_h
#define PlayScreen_h
#include "GameEntity.h"
#include "Texture.h"

class PlayScreen: public GameEntity {
public:

    PlayScreen();
    ~PlayScreen();


    void Update();
    void Render();
    std::string Events(int x, int y);

private:

    //title
    GameEntity* title;
    Texture* name;
    
    GameEntity* blocks;
    GameEntity* board;
    GameEntity* buttons;
    
    Texture* restart;
    Texture* quit;
    Texture* gameBoard;
    Texture* mainBlock;
    Texture* tiger;
    Texture* pig;
    Texture* panda;
    Texture* fox;
    Texture* zebra;
    Texture* startGame;
    Texture* showScores;
    Texture* instructions;
    Texture* exitGame;

};

#endif /* PlayScreen_h */
