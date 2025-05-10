#include "Triangulo.h"
#include "IncludeGL.h"

Triangulo::Triangulo():Figura2D()
{

}

void Triangulo::Draw()
{
    glColor3f(color.r, color.g, color.b);

    glBegin(GL_TRIANGLES);

        glVertex2f(-0.5f, -0.5f); 
        glVertex2f(0.5f, -0.5f);  
        glVertex2f(0.0f, 0.5f);  

    glEnd();
}
