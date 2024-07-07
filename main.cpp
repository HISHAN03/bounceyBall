// main.cpp

#include "myglut.h"

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1100, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Game");

    glutDisplayFunc(myDisplay);
    glutIdleFunc(update);  // Call update in the idle loop
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboardUp);
    myInit();
    glutMainLoop();

    return 0;
}
