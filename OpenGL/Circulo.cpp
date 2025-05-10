#include "Circulo.h"
#include "IncludeGL.h"
#include <cmath>
Circulo::Circulo():Figura2D()
{

}

void Circulo::Draw()
{
    glPushMatrix(); 
    transform.applyTransformations(); 
    ApplyTexture();  
    glColor3f(color.r, color.g, color.b);   

    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 10)
    {
        float x = 0.5f * cos(i * 3.14159f / 180.0f);
        float y = 0.5f * sin(i * 3.14159f / 180.0f);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();
}
