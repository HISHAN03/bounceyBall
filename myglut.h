// myglut.h
#ifndef MYGLUT_H
#define MYGLUT_H

#include <GL/glut.h>
#include <vector>

// Constants
const float pi = 3.142857;

// Game states
enum GameState {
    MENU,
    GAME,
    GAME_OVER
};

// Circle struct
struct Circle {
    float x, y, radius;
};

// Global variables
extern GameState gameState;
extern int c, d, left, right;
extern int m, j, flag1, l, flag2, n, score, count;
extern bool moveLeft, moveRight;
extern std::vector<Circle> circles;
extern int highScore; // Declare high score

void myInit(void);
void myDisplay(void);
void keyboard(unsigned char key, int x, int y);
void keyboardUp(unsigned char key, int x, int y);
void update(void);
void updateBallPosition(void);
void drawMenu(void);
void drawGameOver(void);
void initializeCircles(void);
void resetGame(void);

#endif // MYGLUT_H
