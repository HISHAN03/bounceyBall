#include "myglut.h"
#include <cstdlib>
#include <ctime>
#include <vector>


GameState gameState = MENU;
int c = 0, d = 0, left = -200, right = 200;
int m = 0, j = 1, flag1 = 0, l = 1, flag2 = 0, n = 0, score = 0, count = 1;
bool moveLeft = false;
bool moveRight = false;
std::vector<Circle> circles;
int highScore = 0;

void initializeCircles() {
    circles.clear();
   
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    
    for (int i = 0; i < 15; ++i) {
        Circle c;
        c.x = static_cast<float>((std::rand() % 1100) - 550); 
        c.y = static_cast<float>(std::rand() % 240 + 60);     
        c.radius = 10.0f;                                     
        
        
        if (c.x - c.radius < -600) c.x = -600 + c.radius;
        if (c.x + c.radius > 600) c.x = 600 - c.radius;
        if (c.y + c.radius > 320) c.y = 320 - c.radius;
        
        circles.push_back(c);
    }
}

void resetGame() {
  
    m = 0; j = 1; n = 0; score = 0;
    left = -200; right = 200;
    moveLeft = moveRight = false;
   
