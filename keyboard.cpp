#include "myglut.h"

void keyboard(unsigned char key, int x, int y)
{
    if (gameState == MENU) {
        gameState = GAME;
    } else if (gameState == GAME_OVER) {
        if (key == 'q') {
            exit(0);  // Quit the game
        } else {
            gameState = GAME;
            resetGame(); // Reset the game on restart without reinitializing circles
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
