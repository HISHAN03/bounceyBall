// keyboard.cpp

#include "myglut.h"

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'b')
    {
        moveLeft = true;
    }
    else if (key == 'n')
    {
        moveRight = true;
    }
}

void keyboardUp(unsigned char key, int x, int y)
{
    if (key == 'b')
    {
        moveLeft = false;
    }
    else if (key == 'n')
    {
        moveRight = false;
    }
}
