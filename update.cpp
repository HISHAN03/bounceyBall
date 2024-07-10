#include "myglut.h"
#include <cmath>
#include <iostream>

bool checkCollision(float x1, float y1, float r1, float x2, float y2, float r2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    float distance = sqrt(dx * dx + dy * dy);
    return distance < (r1 + r2);
}

void update()
{
    if (gameState != GAME) {
        return;
    }

   
    if (moveLeft && left > -600) {
        left -= 5;
        right -= 5;
    }
    if (moveRight && right < 600) {
        left += 5;
        right += 5;
    }
    if (score > highScore) {
        highScore = score;
    }

    updateBallPosition();
    glutPostRedisplay(); 
}

void updateBallPosition()
{
   
    m += 6 * j;
    n += 4 * l;

 
    if (m >= 288) {
        j = -1;  
    }

   
    if (m <= -276) {
        if (left <= (n + 20) && right >= (n - 20)) {
          
            j = 1;
            score++;
        } else {
           
            gameState = GAME_OVER;
        }
    }

   
    if (n >= 580 || n <= -580) {
        l = -l;  

   
    for (auto it = circles.begin(); it != circles.end();) {
        if (checkCollision(n, m, 20, it->x, it->y, it->radius)) {
            j = -j; 
            l = -l; 
            it = circles.erase(it); 
        } else {
            ++it;
        }
    }
}
