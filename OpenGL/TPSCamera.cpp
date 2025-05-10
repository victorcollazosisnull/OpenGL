#include "TPSCamera.h"
#include "IncludeGL.h"
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846 
#endif
TPSCamera::TPSCamera()
    : distance(10.0f), angle(45.0f), height(5.0f) 
{
}


void TPSCamera::follow(const Vector3D& targetPosition)
{
    float x = targetPosition.x + distance * cos(angle * M_PI / 180.0f);
    float z = targetPosition.z + distance * sin(angle * M_PI / 180.0f);
    float y = targetPosition.y + height;  

    transform.translate(Vector3D(x, y, z));
}

void TPSCamera::updateCamera()
{
    Vector3D pos = transform.getTranslation();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(pos.x, pos.y, pos.z, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
}
