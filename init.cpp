
#include "myglut.h"

void myInit(void)
{
    

    // Reset background color with white (since all three arguments are 1.0)
     glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    // Set picture color to red (in RGB model)
    // as only argument corresponding to R (Red) is 1.0 and rest are 0.0
    glColor3f(1.0f, 0.0f, 0.0f);

    // Set width of point to one unit
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Set window size in X- and Y- direction
    gluOrtho2D(-620.0, 620.0, -340.0, 340.0);

    initializeCircles(); // Initialize circles once
    resetGame();         // Reset game variables
}
