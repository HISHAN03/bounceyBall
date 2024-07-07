// myglut.h

#ifndef MYGLUT_H
#define MYGLUT_H

#include <GL/glut.h>

// Constants
const float pi = 3.142857;

// Global variables
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

#endif // MYGLUT_H
