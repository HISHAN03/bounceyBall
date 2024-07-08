#include <iostream>
#include <cmath>
#include "myglut.h"

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (gameState == MENU) {
        drawMenu();
    } else if (gameState == GAME) {
        // Draw the ball
        glBegin(GL_LINE_STRIP);
        float i = 0;
        int x, y;
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

        // Draw the circles
        for (const auto& circle : circles) {
            glBegin(GL_LINE_LOOP);
            for (int j = 0; j < 360; j++) {
                float theta = j * pi / 180;
                float x = circle.radius * cos(theta);
                float y = circle.radius * sin(theta);
                glVertex2i(circle.x + x, circle.y + y);
            }
            glEnd();
        }
    } else if (gameState == GAME_OVER) {
        drawGameOver();
    }

    glutSwapBuffers();
}

void drawMenu()
{
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(-200, 0);
    std::string menuText = "Press any key to start";
    for (char c : menuText) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
    glRasterPos2i(-200, -50);
    std::string instructions = "Use 'b' and 'n' keys to move the catcher";
    for (char c : instructions) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
}

void drawGameOver()
{
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(-200, 0);
    std::string gameOverText = "Game Over!!!";
    for (char c : gameOverText) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
    glRasterPos2i(-200, -50);
    std::string scoreText = "Your Score is: " + std::to_string(score);
    for (char c : scoreText) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
    glRasterPos2i(-200, -100);
    std::string optionsText = "Press 'q' to quit, any other key to restart";
    for (char c : optionsText) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
}
