// myglut.h

#ifndef MYGLUT_H
#define MYGLUT_H

#include <GL/glut.h>

// Constants
const float pi = 3.142857;

// Game states
enum GameState {
    MENU,
    GAME,
    GAME_OVER
};

// Global variables
extern GameState gameState;
extern int c, d, left, right;
extern int m, j, flag1, l, flag2, n, score, count;
extern bool moveLeft, moveRight;

// Function declarations
void myInit(void);
void myDisplay(void);
void keyboard(unsigned char key, int x, int y);
void keyboardUp(unsigned char key, int x, int y);
void update(void);
void updateBallPosition(void);
void drawMenu(void);
void drawGameOver(void);

#endif // MYGLUT_H
