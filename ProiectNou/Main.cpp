// THE DARK KNIGHT logo openGL code
//--Brad

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

float j = 0;
int flag = 0;

void init() {
    glClearColor(1, 1, 1, 0.0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glShadeModel(GL_SMOOTH);

    float lightpos[] = { 0, 0, 30, 0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

    glMatrixMode(GL_PROJECTION | GL_MODELVIEW);
    glLoadIdentity();
    gluPerspective(100, 640 / 480, 1, 30);
    gluLookAt(0, 1, 9, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glPointSize(5);
}

void drawrefx(double x, double y, double z) {
    glVertex3d(-x, y, z);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(0, 0, 0);
    glRotatef(0.4, 0, 1, 0);
    glTranslatef(0, .4, 0);
    glutWireCube(5);
    glTranslatef(0, -.4, 0);

    // Draw logo polygons
    glBegin(GL_POLYGON);
    glVertex3d(0, 1.4, 0);
    glVertex3d(.1, 1.37, 0);
    glVertex3d(.2, 1.35, 0);
    glVertex3d(.2, 0, 0);
    glVertex3d(0, 0, 0);
    glEnd();

    // ... (rest of the polygon drawing code)

    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(700, 700);
    glutCreateWindow("Batman");
    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}