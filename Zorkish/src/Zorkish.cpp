#include <iostream>

#include "GameManager.h"

int main(int argc, char* argv[])
{
    GameManager gameManager;

    gameManager.RunGame();
    
    gameManager.~GameManager();

    return 0;
}