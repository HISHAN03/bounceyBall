// update.cpp

#include "myglut.h"
#include <iostream>

void update()
{
    if (gameState != GAME) {
        return;
    }

    // Update the rectangle's position based on the keys pressed
    if (moveLeft && left > -600)
    {
        left -= 5;
        right -= 5;
    }
    if (moveRight && right < 600)
    {
        left += 5;
        right += 5;
    }

    updateBallPosition();
    glutPostRedisplay(); // Request a redraw
}

void updateBallPosition()
{
    // Update ball position
    m += 6 * j;
    n += 4 * l;

    // Check for collision with the top bound
    if (m >= 288)
    {
        j = -1;  // Reverse vertical direction
    }

    // Check for collision with the floor
    if (m <= -276)
    {
        if (left <= (n + 20) && right >= (n - 20))
        {
            // Ball hits the catcher, bounce back
            j = 1;
            score++;
        }
        else
        {
            // Ball misses the catcher, game over
            gameState = GAME_OVER;
        }
    }

    // Check for collision with left and right bounds
    if (n >= 580 || n <= -580)
    {
        l = -l;  // Reverse horizontal direction
    }
}
