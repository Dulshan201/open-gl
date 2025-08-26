#include <GL/glut.h>
#include <iostream>
using namespace std;

// Function to plot a single pixel
void plotPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

// Bresenham's Line Algorithm (0 < m < 1)
void bresenhamLine(int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int p = 2 * dy - dx;   // initial decision parameter

    int x = x0;
    int y = y0;

    plotPixel(x, y);

    while (x < x1) {
        x++;
        if (p < 0) {
            p += 2 * dy;
        } else {
            y++;
            p += 2 * (dy - dx);
        }
        plotPixel(x, y);
    }
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Example: draw a line from (50, 100) to (300, 200)
    bresenhamLine(50, 100, 300, 200);

    glFlush();
}

// Initialize OpenGL
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);   // Black background
    glColor3f(1.0, 1.0, 1.0);           // White drawing color
    glPointSize(3.0);                   // Point size
    gluOrtho2D(0, 500, 0, 500);         // Coordinate system (0,0) to (500,500)
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham's Line Drawing (0 < m < 1)");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
