#pragma once
#include "Transform.h"

class CameraFPS
{
private:
    float rotationAngleX;  
    float rotationAngleY; 
    float sensitivity;
public:
    CameraFPS();
    void init();
    void KeyboardFunc(unsigned char key, int X, int Y);
    void updateCamera();
    void MouseRotate(float deltaX, float deltaY);
    Transform transform;
};