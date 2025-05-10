#include <iostream>
#include "CameraFPS.h"
#include "IncludeGL.h"
#include <cmath>

CameraFPS::CameraFPS()
    : rotationAngleX(0.0f), rotationAngleY(0.0f), sensitivity(0.2f)
{
}

void CameraFPS::init()
{
    updateCamera();
}

void CameraFPS::KeyboardFunc(unsigned char key, int X, int Y)
{
    std::cout << key;
    Vector3D pos = transform.getTranslation();
    switch (key)
    {
    case 'w':  
        transform.translate(pos+Vector3D(0,0,-1));  
        break;
    case 's':  
        transform.translate(pos+Vector3D(0, 0, 1));
        break;
    case 'a':  
        transform.translate(pos+Vector3D(1, 0, 0));
        break;
    case 'd':  
        transform.translate(pos+Vector3D(-1, 0, 0));
        break;
    default:
        break;
    }
    updateCamera();
}

void CameraFPS::updateCamera()
{
    Vector3D pos = transform.getTranslation();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(pos.x, pos.y, pos.z, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(rotationAngleX, 1.0f, 0.0f, 0.0f);  
    glRotatef(rotationAngleY, 0.0f, 1.0f, 0.0f);
}

void CameraFPS::MouseRotate(float deltaX, float deltaY)
{
    rotationAngleY += deltaX * sensitivity; 
    rotationAngleX -= deltaY * sensitivity; 

    float maxPitch = 1.55f; 
    if (rotationAngleX > maxPitch)
        rotationAngleX = maxPitch;
    if (rotationAngleX < -maxPitch)
        rotationAngleX = -maxPitch;

    updateCamera();

}
