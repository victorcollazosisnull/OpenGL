#include "Example6.h"
#include "IncludeGL.h"
Example6::Example6()
{
}

void Example6::init()
{
    glEnable(GL_DEPTH_TEST);
    displayListID = glGenLists(1);

    glNewList(displayListID, GL_COMPILE);

    glPushMatrix();
    glTranslatef(-10.0f, 0.0f, 0.0f); 

    glColor3f(0.8f, 0.5f, 0.2f); 
    glutSolidCube(4.0f);

    glTranslatef(0.0f, 2.0f, 0.0f);
    glRotatef(-90, 1, 0, 0);
    glColor3f(0.7f, 0.0f, 0.0f); 
    glutSolidCone(3.5f, 2.5f, 4, 4);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -10.0f);

    glColor3f(0.55f, 0.27f, 0.07f);
    glPushMatrix();
    glTranslatef(0.0f, 1.0f, 0.0f);
    glRotatef(-90, 1, 0, 0);
    glutSolidCylinder(0.3f, 2.0f, 10, 10);
    glPopMatrix();

    glColor3f(0.0f, 0.8f, 0.0f);
    glTranslatef(0.0f, 2.0f, 0.0f);
    glutSolidSphere(1.0f, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10.0f, 0.0f, 0.0f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glPushMatrix();
    glScalef(3.0f, 1.0f, 1.5f);
    glutSolidCube(2.0f);
    glPopMatrix();

    glColor3f(0.0f, 0.0f, 0.0f);
    float wheelOffset = 1.5f;
    for (int side = -1; side <= 1; side += 2) {
        glPushMatrix();
        glTranslatef(side * 1.2f, -1.0f, wheelOffset);
        glutSolidTorus(0.1f, 0.4f, 10, 10);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(side * 1.2f, -1.0f, -wheelOffset);
        glutSolidTorus(0.1f, 0.4f, 10, 10);
        glPopMatrix();
    }
    glPopMatrix();

    glEndList();
}

void Example6::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(10, 10, 30, 0, 0, 0, 0, 1, 0);

    glCallList(displayListID);

    glutSwapBuffers();
}

void Example6::KeyboardFunc(unsigned char key, int X, int Y)
{
}

void Example6::Idle()
{
}
 