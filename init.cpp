
#include "myglut.h"

void myInit(void)
{
    

   
     glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

  
    glColor3f(1.0f, 0.0f, 0.0f);

    
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

  
    gluOrtho2D(-620.0, 620.0, -340.0, 340.0);

    initializeCircles(); 
    resetGame();         
}
