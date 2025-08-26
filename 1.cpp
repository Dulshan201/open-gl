#include <GL/glut.h>

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a line segment
    glBegin(GL_LINES);
        glVertex2i(180, 15);   // Start point
        glVertex2i(10, 145);   // End point
    glEnd();

    glFlush();
}

// Initialize OpenGL
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);   // Black background
    glColor3f(1.0, 1.0, 1.0);           // White line color
    glPointSize(3.0);                   // Line thickness
    gluOrtho2D(0, 500, 0, 500);         // Set coordinate system (x:0-500, y:0-500)
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Basic Line Segment with OpenGL");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
