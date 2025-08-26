#include <GL/glut.h>
#include <iostream>
using namespace std;

int xc, yc, r; // Circle center and radius (from user input)

// Function to plot symmetric points in all 8 octants
void plotCirclePoints(int x, int y) {
    glBegin(GL_POINTS);
        glVertex2i( xc + x, yc + y);
        glVertex2i( xc - x, yc + y);
        glVertex2i( xc + x, yc - y);
        glVertex2i( xc - x, yc - y);
        glVertex2i( xc + y, yc + x);
        glVertex2i( xc - y, yc + x);
        glVertex2i( xc + y, yc - x);
        glVertex2i( xc - y, yc - x);
    glEnd();
}

// Midpoint Circle Drawing Algorithm
void midpointCircle(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int p = 1 - r;  // initial decision parameter

    plotCirclePoints(x, y);

    while (x < y) {
        x++;
        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * (x - y) + 1;
        }
        plotCirclePoints(x, y);
    }
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw circle using midpoint algorithm
    midpointCircle(xc, yc, r);

    glFlush();
}

// Initialize OpenGL
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);   // Black background
    glColor3f(1.0, 1.0, 1.0);           // White points
    glPointSize(3.0);                   // Point size
    gluOrtho2D(0, 500, 0, 500);         // Coordinate system
}

int main(int argc, char** argv) {
    // Get user input
    cout << "Enter circle center (xc yc): ";
    cin >> xc >> yc;
    cout << "Enter radius: ";
    cin >> r;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Midpoint Circle Drawing Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
