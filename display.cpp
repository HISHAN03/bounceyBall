#include <iostream>
#include <cmath>
#include "myglut.h"

void drawCircle(float cx, float cy, float radius, int segments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i <= segments; ++i) {
        float angle = 2 * pi * i / segments;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

void drawScore(int score) {
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(-590, 300);
    std::string scoreText = "Score: " + std::to_string(score);
    for (char c : scoreText) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (gameState == MENU) {
        drawMenu();
    } else if (gameState == GAME) {
        // Draw the ball
        glColor3f(1.0f, 0.0f, 0.0f);
        glLineWidth(3.0f); // Red color for the ball
        glBegin(GL_POLYGON);
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
        glColor3f(0.0f, 0.0f, 0.0f);
        glLineWidth(4.0f); // Black color for the outer rectangle
        glBegin(GL_LINE_LOOP);
        glVertex2i(-600, -320);
        glVertex2i(-600, 320);
        glVertex2i(600, 320);
        glVertex2i(600, -320);
        glEnd();

        // Draw the filled catcher rectangle
        glColor3f(0.4f, 0.26f, 0.13f);
        glLineWidth(3.0f); // Dark brown color for the catcher
        glBegin(GL_POLYGON);
        glVertex2i(left, -315);
        glVertex2i(right, -315);
        glVertex2i(right, -295);
        glVertex2i(left, -295);
        glEnd();

        // Draw circles
        for (const auto& circle : circles) {
         glColor3f(0.5f, 0.0f, 0.5f);// violet color for the circles
            glBegin(GL_POLYGON);
            for (float angle = 0; angle < 2 * pi; angle += 0.1) {
                glVertex2i(circle.x + circle.radius * cos(angle), circle.y + circle.radius * sin(angle));
            }
            glEnd();

         
        }
        

        

        // Draw score
        drawScore(score);
    } else if (gameState == GAME_OVER) {
        drawGameOver();
    }

    glutSwapBuffers();
}

void drawMenu()
{
    // Draw the game title
    glColor3f(0.0, 0.0, 0.0); // Black color
    glRasterPos2i(-200, 100); // Position for the title
    std::string gameTitle = "Bounce Ball";
    for (char c : gameTitle) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }

    // Draw the menu instructions
    glRasterPos2i(-200, 0);
    std::string menuText = "Press any key to start";
    for (char c : menuText) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    glRasterPos2i(-200, -50);
    std::string instructions = "Use 'b' and 'n' keys to move the catcher";
    for (char c : instructions) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
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
    std::string finalScoreText = "Your Score is: " + std::to_string(score);
    for (char c : finalScoreText) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
    glRasterPos2i(-200, -100);
    std::string optionsText = "Press 'q' to quit, any other key to restart";
    for (char c : optionsText) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
}
