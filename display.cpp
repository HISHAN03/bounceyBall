// display.cpp

#include <iostream>
#include <cmath>
#include "myglut.h"

void myDisplay()
{
    int x, y;
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the ball
    glBegin(GL_LINE_STRIP);
    float i = 0;
    while (i <= 2 * pi)
    {
        y = 12 + 20 * cos(i);
        x = 20 * sin(i);
        i += 0.1;
        glVertex2i((x + n), (y + m));
    }
    glEnd();

    // Draw outer rectangle
    glBegin(GL_LINE_LOOP);
    glVertex2i(-600, -320);
    glVertex2i(-600, 320);
    glVertex2i(600, 320);
    glVertex2i(600, -320);
    glEnd();

    // Draw the catcher rectangle
    glBegin(GL_LINE_LOOP);
    glVertex2i(left, -315);
    glVertex2i(left, -295);
    glVertex2i(right, -295);
    glVertex2i(right, -315);
    glEnd();

    glutSwapBuffers();
}
