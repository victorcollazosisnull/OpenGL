#include "Cuadrado.h"
#include "IncludeGL.h"

Cuadrado::Cuadrado():Figura2D()
{

}

void Cuadrado::Draw()
{
    glPushMatrix();
    transform.applyTransformations(); 
    ApplyTexture();  
    glColor3f(color.r, color.g, color.b); 

    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();
    glPopMatrix();
}
