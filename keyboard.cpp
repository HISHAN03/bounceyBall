// keyboard.cpp

#include "myglut.h"

void keyboard(unsigned char key, int x, int y)
{
    if (gameState == MENU) {
        gameState = GAME;
    } else if (gameState == GAME_OVER) {
        if (key == 'q') {
            exit(0);  // Quit the game
        } else {
            // Restart the game
            gameState = GAME;
            // Reset game variables
            m = 0; j = 1; n = 0; score = 0;
            left = -200; right = 200;
            moveLeft = moveRight = false;
        }
    } else if (gameState == GAME) {
        if (key == 'b') {
            moveLeft = true;
        } else if (key == 'n') {
            moveRight = true;
        }
    }
}

void keyboardUp(unsigned char key, int x, int y)
{
    if (key == 'b') {
        moveLeft = false;
    } else if (key == 'n') {
        moveRight = false;
    }
}
