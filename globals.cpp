#include "myglut.h"
#include <cstdlib>
#include <ctime>
#include <vector>

// Global variables
GameState gameState = MENU;
int c = 0, d = 0, left = -200, right = 200;
int m = 0, j = 1, flag1 = 0, l = 1, flag2 = 0, n = 0, score = 0, count = 1;
bool moveLeft = false;
bool moveRight = false;
std::vector<Circle> circles;
int highScore = 0;

void initializeCircles() {
    circles.clear();
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    // Add 15 circles in fixed positions within the top part of the game area
    for (int i = 0; i < 15; ++i) {
        Circle c;
        c.x = static_cast<float>((std::rand() % 1100) - 550); // Random x position within the window width
        c.y = static_cast<float>(std::rand() % 240 + 60);     // Random y position within the top part
        c.radius = 10.0f;                                      // Fixed radius for simplicity
        
        // Ensure circle does not exceed outer bounds
        if (c.x - c.radius < -600) c.x = -600 + c.radius;
        if (c.x + c.radius > 600) c.x = 600 - c.radius;
        if (c.y + c.radius > 320) c.y = 320 - c.radius;
        
        circles.push_back(c);
    }
}

void resetGame() {
    // Reset game variables
    m = 0; j = 1; n = 0; score = 0;
    left = -200; right = 200;
    moveLeft = moveRight = false;
    // Do not reinitialize the circles
}
