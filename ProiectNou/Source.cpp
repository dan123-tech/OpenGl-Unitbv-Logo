#include <GL/glut.h>
class Line {
private:
    float x1, y1, z1;
    float x2, y2, z2;
    float width;

public:
    Line(float startX, float startY, float startZ, float endX, float endY, float endZ, float lineWidth)
        : x1(startX), y1(startY), z1(startZ), x2(endX), y2(endY), z2(endZ), width(lineWidth) {}

    void draw() const {
        glLineWidth(width);
        glBegin(GL_LINES);
        glVertex3f(x1, y1, z1);
        glVertex3f(x2, y2, z2);
        glEnd();
    }
};

class ShortLine {
private:
    float x1, y1, z1;
    float x2, y2, z2;
    float width;

public:
    ShortLine(float startX, float startY, float startZ, float endX, float endY, float endZ, float lineWidth)
        : x1(startX), y1(startY), z1(startZ), x2(endX), y2(endY), z2(endZ), width(lineWidth) {}

    void draw() const {
        glLineWidth(width);
        glBegin(GL_LINES);
        glVertex3f(x1, y1, z1);
        glVertex3f(x2, y2, z2);
        glEnd();
    }
};

class LongVerticalLine {
private:
    float x1, y1, z1;
    float x2, y2, z2;
    float width;

public:
    LongVerticalLine(float startX, float startY, float startZ, float endX, float endY, float endZ, float lineWidth)
        : x1(startX), y1(startY), z1(startZ), x2(endX), y2(endY), z2(endZ), width(lineWidth) {}

    void draw() const {
        glLineWidth(width);
        glBegin(GL_LINES);
        glVertex3f(x1, y1, z1);
        glVertex3f(x2, y2, z2);
        glEnd();
    }
};

class DoubleLine {
private:
    float x1, y1, z1;
    float x2, y2, z2;
    float x3, y3, z3;
    float x4, y4, z4;
    float width;

public:
    DoubleLine(float startX, float startY, float startZ, float endX, float endY, float endZ, float lineWidth)
        : x1(startX), y1(startY), z1(startZ), x2(endX), y2(endY), z2(endZ), width(lineWidth) {
        y3 = startY;
        z3 = startZ;
        x3 = startX + 50.0;
        y4 = endY;
        z4 = endZ;
        x4 = endX + 50.0;
    }

    void draw() const {
        glLineWidth(width);
        glBegin(GL_LINES);
        glVertex3f(x1, y1, z1);
        glVertex3f(x2, y2, z2);
        glVertex3f(x3, y3, z3);
        glVertex3f(x4, y4, z4);
        glEnd();
    }
};

Line* line1;
Line* line2;
ShortLine* square[4];
LongVerticalLine* verticalLine1Right;
LongVerticalLine* verticalLine2Right;
LongVerticalLine* verticalLine1Left;
LongVerticalLine* verticalLine2Left;
DoubleLine* doubleLine;
int windowWidth = 800;
int windowHeight = 600;

bool mousePressed = false;
int lastMouseX, lastMouseY;
float offsetX = 0.0f, offsetY = 0.0f; float offsetZ = 0.0f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(offsetX, offsetY, 0);

    line1->draw();
    line2->draw();

    for (int i = 0; i < 4; ++i) {
        square[i]->draw();
    }

    verticalLine1Right->draw();
    verticalLine2Right->draw();

    verticalLine1Left->draw();
    verticalLine2Left->draw();

    glPopMatrix();
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, windowWidth, 0.0, windowHeight);
}

void mousePressedFunc(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mousePressed = true;
        lastMouseX = x;
        lastMouseY = y;
    }
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        mousePressed = false;
    }
}

void mouseMovedFunc(int x, int y) {
    if (mousePressed) {
        offsetX += (x - lastMouseX);
        offsetY -= (y - lastMouseY);
        offsetZ += (y - lastMouseY);
        lastMouseX = x;
        lastMouseY = y;
        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
    float startX = 100.0;
    float startY = windowHeight - 100.0;
    float startZ = 0.0;
    float endX = 700.0;
    float endY = windowHeight - 100.0;
    float endZ = 0.0;
    float lineWidth = 40.0;

    line1 = new Line(startX, startY, startZ, endX, endY, endZ, lineWidth);

    float secondLineStartY = startY - 50.0;
    float secondLineEndY = endY - 50.0;

    line2 = new Line(startX, secondLineStartY, startZ, endX, secondLineEndY, endZ, lineWidth);

    float squareSize = 100.0;
    float squareStartX = (startX + endX - squareSize) / 2;
    float squareStartY = secondLineStartY - 150.0;

    square[0] = new ShortLine(squareStartX, squareStartY, startZ, squareStartX + squareSize, squareStartY, startZ, lineWidth);
    square[1] = new ShortLine(squareStartX + squareSize, squareStartY, startZ, squareStartX + squareSize, squareStartY + squareSize, startZ, lineWidth);
    square[2] = new ShortLine(squareStartX + squareSize, squareStartY + squareSize, startZ, squareStartX, squareStartY + squareSize, startZ, lineWidth);
    square[3] = new ShortLine(squareStartX, squareStartY + squareSize, startZ, squareStartX, squareStartY, startZ, lineWidth);

    float verticalLineStartXRight = squareStartX + squareSize + 50.0;
    float verticalLineStartY = squareStartY + squareSize;
    float verticalLineEndXRight = verticalLineStartXRight;
    float verticalLineEndY = verticalLineStartY - (2 * squareSize) - 50.0;

    verticalLine1Right = new LongVerticalLine(verticalLineStartXRight, verticalLineStartY, startZ, verticalLineEndXRight, verticalLineEndY, startZ, lineWidth);
    verticalLine2Right = new LongVerticalLine(verticalLineStartXRight + 100.0, verticalLineStartY, startZ, verticalLineEndXRight + 100.0, verticalLineEndY, startZ, lineWidth);

    float verticalLineStartXLeft = squareStartX - 50.0;
    float verticalLineEndXLeft = verticalLineStartXLeft;

    verticalLine1Left = new LongVerticalLine(verticalLineStartXLeft, verticalLineStartY, startZ, verticalLineEndXLeft, verticalLineEndY, startZ, lineWidth);
    verticalLine2Left = new LongVerticalLine(verticalLineStartXLeft - 100.0, verticalLineStartY, startZ, verticalLineEndXLeft - 100.0, verticalLineEndY, startZ, lineWidth);

    doubleLine = new DoubleLine(startX, squareStartY - 50, startZ, endX, squareStartY - 50, endZ, lineWidth);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Desenare Linii Orizontale, Patrat si Linii Verticale");

    init();

    glutDisplayFunc(display);
    glutMouseFunc(mousePressedFunc);
    glutMotionFunc(mouseMovedFunc);

    glutMainLoop();

    delete line1;
    delete line2;
    for (int i = 0; i < 4; ++i) {
        delete square[i];
    }
    delete verticalLine1Right;
    delete verticalLine2Right;
    delete verticalLine1Left;
    delete verticalLine2Left;
    delete doubleLine;

    return 0;
}
