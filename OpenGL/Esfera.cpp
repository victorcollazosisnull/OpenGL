#include "Esfera.h"
#include "IncludeGL.h"
#include <GL/gl.h>
Esfera::Esfera():Figura3D()
{

}

void Esfera::Draw()
{
    glColor3f(color.r, color.g, color.b); 
    transform.applyTransformations(); 
    glutSolidSphere(0.5, 50, 50);
    ApplyTexture();
}