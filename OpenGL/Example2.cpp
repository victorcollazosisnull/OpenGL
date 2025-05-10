#include "Example2.h"
#include "IncludeGL.h"
#include <cmath>
#include "Esfera.h"
#include "Cuadrado.h"
#include "Cubo.h"
#include "Piramide.h"
#include "Circulo.h"
#include "Triangulo.h"
Example2::Example2()
{

}
Vector3D cuboPos(0, 0, 0);
float rotationX = 0.0f; 
float rotationY = 0.0f;  
float rotationZ = 0.0f;
Vector3D cuboScale(1, 1, 1);
void Example2::init()
{

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0);
    gluLookAt(10, 10, 20, 0, 0, 0, 0, 1, 0);
    glMatrixMode(GL_MODELVIEW);
}

void Example2::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Example::DrawAxis(10);
    //DrawTransformedPoint(0, 0, 0, 0, 0, 0);
    //DrawTransformedLines();
    //DrawTransformedXYAxis();
    //DrawTransformedPointWithAxes(0, 0, 0, 0, 0, 0);  
    //DrawTransformedCube(1.0f, 0.0f, 0.0f, 0.0f);

    //DrawTransformedSphere(1.0f, 3.0f, 0.0f, 0.0f);
    //DrawTransformedPyramid(2.0f, 0.0f, 3.0f, 0.0f);
    //DrawTransformedRectangle(3.0f, 1.5f, -3.0f, -3.0f, 0.0f);
    //DrawTransformedSquare(2.0f, 3.0f, -3.0f, 0.0f);
    //DrawTransformedCircle(1.5f, 0.0f, -3.0f, 0.0f);

    //Esfera esfera;
    //Piramide piramide;
    //Circulo circulo;
    //Triangulo triangulo;
    //Cuadrado cuadrado;

    Cubo cubo;
    cubo.setTranslation(cuboPos);  
    cubo.setRotation(rotationX, Vector3D(1.0f, 0.0f, 0.0f));  
    cubo.setRotation(rotationY, Vector3D(0.0f, 1.0f, 0.0f));  
    cubo.setRotation(rotationZ, Vector3D(0.0f, 0.0f, 1.0f));
    cubo.setScale(cuboScale);
    cubo.Draw();

    //esfera.setTranslation(Vector3D(-2, 1, 0));
    //esfera.setScale(Vector3D(1.2, 1.2, 1.2));
    //esfera.Draw();

    //piramide.setTranslation(Vector3D(0, -1, 2));
    //piramide.setRotation(30, Vector3D(1, 0, 0));
    //piramide.Draw();

    glFlush();
}

void Example2::KeyboardFunc(unsigned char key, int X, int Y)
{
    float step = 1.0f;  
    float rotationStep = 5.0f; 
    float scaleStep = 0.1f;
    switch (key) {
    case 'w':  
        cuboPos.z -= step;
        break;
    case 's':  
        cuboPos.z += step;
        break;
    case 'a':  
        cuboPos.x -= step;
        break;
    case 'd':  
        cuboPos.x += step;
        break;
    case 'q':  
        cuboPos.y += step;
        break;
    case 'e': 
        cuboPos.y -= step;
        break;
    case 'r':  
        rotationX += rotationStep;
        break;
    case 't':  
        rotationY += rotationStep;
        break;
    case 'y':  
        rotationZ += rotationStep;
        break;
    case '+':  
        cuboScale.x += scaleStep;
        cuboScale.y += scaleStep;
        cuboScale.z += scaleStep;
        break;
    case '-':  
        cuboScale.x -= scaleStep;
        cuboScale.y -= scaleStep;
        cuboScale.z -= scaleStep;
        break;
    case 27: 
        exit(0);
        break;
    }

    glutPostRedisplay(); 
}

void Example2::Idle()
{

}
void Example2::DrawAxis(float distance)
{

}

void Example2::DrawGrids()
{

}

void Example2::DrawTransformedPoint(float x, float y, float z, float translateX, float translateY, float translateZ)
{
    glPushMatrix(); 
         
        glTranslatef(translateX, translateY, translateZ);
        Example::DrawAxis(5);

        glPointSize(10);
        glBegin(GL_POINTS); 
            glColor3f(1.0f, 1.0f, 0.0f); 
            glVertex3f(x, y, z);
        glEnd();
    glPopMatrix();
}

void Example2::DrawTransformedLines()
{
    glPushMatrix(); 

        glTranslatef(1.0f, 1.0f, 0.0f);
        glRotatef(45, 0, 0, 1); 
        glScalef(9.0f, 3.0f, 3.0f); 

        glLineWidth(5.0f); 
        glColor3f(0.0f, 1.0f, 1.0f); 

        glBegin(GL_LINES);
            glVertex3f(-1.0f, -1.0f, 0.0f); 
            glVertex3f(1.0f, 1.0f, 0.0f);  
    glEnd();

    glPopMatrix();
}
void Example2::DrawTransformedXYAxis()
{
    glPushMatrix();

        glTranslatef(2.0f, 2.0f, 0.0f); 
        glRotatef(50, 0, 0, 1); 
        glLineWidth(3.0f); 

        glBegin(GL_LINES);

            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(-5.0f, 0.0f, 0.0f);
            glVertex3f(5.0f, 0.0f, 0.0f);

            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex3f(0.0f, -5.0f, 0.0f);
            glVertex3f(0.0f, 5.0f, 0.0f);

        glEnd();

    glPopMatrix(); 
}
void Example2::DrawTransformedPointWithAxes(float x, float y, float z,float translateX, float translateY, float translateZ)
{
    glPushMatrix(); 

        glTranslatef(translateX, translateY, translateZ); 
        glRotatef(20, 1, 1, 0);
        glScalef(0.5f, 0.5f, 0.5f);

        Example::DrawAxis(7);

        glPointSize(10);
        glBegin(GL_POINTS);

            glColor3f(1.0f, 1.0f, 0.0f); 
            glVertex3f(x, y, z);

        glEnd();

    glPopMatrix(); 
}
void Example2::DrawTransformedCube(float size, float translateX, float translateY, float translateZ)
{
    glPushMatrix();
        glTranslatef(translateX, translateY, translateZ); 
        glTranslatef(-size / 2, -size / 2, -size / 2);
        glRotatef(0, 1, 1, 0); 
        glScalef(1.2f, 1.2f, 1.2f); 
        Example::DrawAxis(size * 1.5f);
        glBegin(GL_QUADS); 
            glColor3f(1.0f, 0.0f, 0.0f); 
            glVertex3f(-size, -size, size);
            glVertex3f(size, -size, size);
            glVertex3f(size, size, size);
            glVertex3f(-size, size, size);

            glColor3f(0.0f, 1.0f, 0.0f); 
            glVertex3f(-size, -size, -size);
            glVertex3f(-size, size, -size);
            glVertex3f(size, size, -size);
            glVertex3f(size, -size, -size);

            glColor3f(0.0f, 0.0f, 1.0f); 
            glVertex3f(-size, -size, -size);
            glVertex3f(-size, -size, size);
            glVertex3f(-size, size, size);
            glVertex3f(-size, size, -size);

            glColor3f(1.0f, 1.0f, 0.0f);
            glVertex3f(size, -size, -size);
            glVertex3f(size, size, -size);
            glVertex3f(size, size, size);
            glVertex3f(size, -size, size);

            glColor3f(1.0f, 0.0f, 1.0f); 
            glVertex3f(-size, size, -size);
            glVertex3f(-size, size, size);
            glVertex3f(size, size, size);
            glVertex3f(size, size, -size);

            glColor3f(0.0f, 1.0f, 1.0f); 
            glVertex3f(-size, -size, -size);
            glVertex3f(size, -size, -size);
            glVertex3f(size, -size, size);
            glVertex3f(-size, -size, size);
        glEnd(); 
    glPopMatrix(); 
}
void Example2::DrawTransformedSphere(float radius, float translateX, float translateY, float translateZ)
{
    glPushMatrix();

    glTranslatef(translateX, translateY, translateZ);
    Example::DrawAxis(radius * 2.0f);

    glColor3f(0.0f, 1.0f, 1.0f); 
    glutSolidSphere(radius, 20, 20);

    glPopMatrix();
}
void Example2::DrawTransformedPyramid(float size, float translateX, float translateY, float translateZ)
{
    glPushMatrix();

        glTranslatef(translateX, translateY, translateZ);
        Example::DrawAxis(size * 1.5f);

        glBegin(GL_TRIANGLES);

            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(0.0f, size, 0.0f);
            glVertex3f(-size, -size, size);
            glVertex3f(size, -size, size);

            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex3f(0.0f, size, 0.0f);
            glVertex3f(size, -size, size);
            glVertex3f(size, -size, -size);

            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex3f(0.0f, size, 0.0f);
            glVertex3f(size, -size, -size);
            glVertex3f(-size, -size, -size);

            glColor3f(1.0f, 1.0f, 0.0f);
            glVertex3f(0.0f, size, 0.0f);
            glVertex3f(-size, -size, -size);
            glVertex3f(-size, -size, size);

        glEnd();
    glPopMatrix();
}
void Example2::DrawTransformedRectangle(float width, float height, float translateX, float translateY, float translateZ)
{
    glPushMatrix();

        glTranslatef(translateX, translateY, translateZ);
        Example::DrawAxis(width * 1.5f);

        glColor3f(1.0f, 0.5f, 0.0f); 
        glBegin(GL_QUADS);
            glVertex3f(-width / 2, -height / 2, 0);
            glVertex3f(width / 2, -height / 2, 0);
            glVertex3f(width / 2, height / 2, 0);
            glVertex3f(-width / 2, height / 2, 0);
        glEnd();

    glPopMatrix();
}

void Example2::DrawTransformedSquare(float size, float translateX, float translateY, float translateZ)
{
    DrawTransformedRectangle(size, size, translateX, translateY, translateZ);
}

void Example2::DrawTransformedCircle(float radius, float translateX, float translateY, float translateZ)
{
    glPushMatrix();

        glTranslatef(translateX, translateY, translateZ);
        Example::DrawAxis(radius * 1.5f);

        glColor3f(0.5f, 0.0f, 1.0f); 
        glBegin(GL_LINE_LOOP);
            for (int i = 0; i < 360; i += 10)
            {
                float theta = i * 3.1415926f / 180.0f;
                glVertex3f(radius * cos(theta), radius * sin(theta), 0);
            }
        glEnd();

    glPopMatrix();
}