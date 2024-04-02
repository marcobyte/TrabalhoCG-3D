#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>

GLfloat cameraDistance = 6.0;
GLfloat rotationAngle = 45.0;

int selectedObjectIndex = -1;

GLfloat objectPositions[3][3] = {{-3.0, 1.5, 0.0}, {1.0, 1.5, -3.5}, {3.0, 0.5, 1.0}};
void init() {
    GLfloat ambient[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat diffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat position[] = {2.0, 6.0, 3.0, 0.0};
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);


    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glLightfv(GL_LIGHT0, GL_POSITION, position);

    GLfloat wallAmbientDiffuse[] = {0.8, 0.0, 0.0, 1.0};
    GLfloat wallSpecular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat wallShininess[] = {100.0};

    glEnable(GL_COLOR_MATERIAL);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, wallAmbientDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, wallSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, wallShininess);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(0.0, cameraDistance, cameraDistance,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);

    glPushMatrix();
    glRotatef(rotationAngle, 0.0, 1.0, 0.0);
    glColor3f(0.8, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex3f(-5.0, 0.0, -5.0);
        glVertex3f(-5.0, 0.0, 5.0);
        glVertex3f(5.0, 0.0, 5.0);
        glVertex3f(5.0, 0.0, -5.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(rotationAngle, 0.0, 1.0, 0.0);
    glColor3f(0.5, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex3f(-5.0, 0.0, -5.0);
        glVertex3f(-5.0, 0.5, -5.0);
        glVertex3f(-5.0, 0.5, 5.0);
        glVertex3f(-5.0, 0.0, 5.0);

        glVertex3f(5.0, 0.0, -5.0);
        glVertex3f(5.0, 0.5, -5.0);
        glVertex3f(5.0, 0.5, 5.0);
        glVertex3f(5.0, 0.0, 5.0);

        glVertex3f(-5.0, 0.0, -5.0);
        glVertex3f(-5.0, 0.5, -5.0);
        glVertex3f(5.0, 0.5, -5.0);
        glVertex3f(5.0, 0.0, -5.0);

        glVertex3f(-5.0, 0.0, 5.0);
        glVertex3f(-5.0, 0.5, 5.0);
        glVertex3f(5.0, 0.5, 5.0);
        glVertex3f(5.0, 0.0, 5.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(rotationAngle, 0.0, 1.0, 0.0);
    glColor3f(0.5, 0.0, 0.0);
    glBegin(GL_QUADS);

        glVertex3f(5.0, 0.0, -5.0);
        glVertex3f(5.0, 5.0, -5.0);
        glVertex3f(5.0, 5.0, 5.0);
        glVertex3f(5.0, 0.0, 5.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(5.5, 0.0, 5.0);
        glVertex3f(5.5, 5.0, 5.0);
        glVertex3f(5.0, 5.0, 5.0);
        glVertex3f(5.0, 0.0, 5.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-5.0, 0.0, -5.0);
        glVertex3f(-5.0, 5.0, -5.0);
        glVertex3f(5.0, 5.0, -5.0);
        glVertex3f(5.0, 0.0, -5.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-5.0, 0.0, -5.5);
        glVertex3f(-5.0, 5.0, -5.5);
        glVertex3f(-5.0, 5.0, -5.0);
        glVertex3f(-5.0, 0.0, -5.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(rotationAngle, 0.0, 1.0, 0.0);
    glColor3f(0.8, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex3f(-5.0, 5.0, -5.0);
        glVertex3f(-5.0, 5.0, -5.5);
        glVertex3f(5.0, 5.0, -5.5);
        glVertex3f(5.0, 5.0, -5.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(rotationAngle, 0.0, 1.0, 0.0);
    glColor3f(0.8, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex3f(5.0, 5.0, 5.0);
        glVertex3f(5.5, 5.0, 5.0);
        glVertex3f(5.5, 5.0, -5.5);
        glVertex3f(5.0, 5.0, -5.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3.0, 1.5, 0.0);
    glScalef(2.0, 2.0, 2.0);
    glRotatef(rotationAngle, 0.0, 1.0, 0.0);
    glColor3f(21.0 / 255.0, 167.0 / 255.0, 206.0 / 255.0);
    glutSolidTeapot(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.0, 1.5, -3.5);
    glScalef(2.0, 2.0, 2.0);
    glRotatef(rotationAngle, 0.0, 1.0, 0.0);
    glColor3f(255.0 / 255.0, 153.0 / 255.0, 0.0 / 255.0);
    glutSolidSphere(1.0, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3.0, 0.5, 1.0);
    glScalef(2.0, 2.0, 2.0);
    glRotatef(rotationAngle, 0.0, 0.0, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glColor3f(158.0 / 255.0, 250.0 / 255.0, 0.0 / 255.0);
    glutSolidTorus(0.3, 1.0, 20, 20);
    glPopMatrix();
    glutSwapBuffers();
}
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            cameraDistance -= 0.1; // Zoom in
            break;
        case GLUT_KEY_DOWN:
            cameraDistance += 0.1; // Zoom out
            break;
    }
    glutPostRedisplay();
}

void moveObject(int index, GLfloat x, GLfloat y, GLfloat z) {
    if (index < 0 || index >= 3) {
        printf("Índice de objeto inválido.\n");
        return;
    }
    objectPositions[index][0] = x;
    objectPositions[index][1] = y;
    objectPositions[index][2] = z;
}

void selectObject(int objectID) {
    selectedObjectIndex = objectID;
    printf("%d", objectID);
}


void selectObjectWithKeys(unsigned char key, int x, int y) {
    switch (key) {
        case 't':
            selectObject(0);
            break;
        case '2':
            selectObject(1);
            break;
        case '3':
            selectObject(2);
            break;
    }
}

void moveObjectWithKeys(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
        case 'W':
            moveObject(selectedObjectIndex, objectPositions[selectedObjectIndex][0], objectPositions[selectedObjectIndex][1], objectPositions[selectedObjectIndex][2] - 0.1);
            break;
        case 'a':
        case 'A':
            moveObject(selectedObjectIndex, objectPositions[selectedObjectIndex][0] - 0.1, objectPositions[selectedObjectIndex][1], objectPositions[selectedObjectIndex][2]);
            break;
        case 's':
        case 'S':
            moveObject(selectedObjectIndex, objectPositions[selectedObjectIndex][0], objectPositions[selectedObjectIndex][1], objectPositions[selectedObjectIndex][2] + 0.1);
            break;
        case 'd':
        case 'D':
            moveObject(selectedObjectIndex, objectPositions[selectedObjectIndex][0] + 0.1, objectPositions[selectedObjectIndex][1], objectPositions[selectedObjectIndex][2]);
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL 3D Scene");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);

    glutKeyboardFunc(selectObjectWithKeys);
    glutKeyboardFunc(moveObjectWithKeys);

    glutMainLoop();
    return 0;
}


