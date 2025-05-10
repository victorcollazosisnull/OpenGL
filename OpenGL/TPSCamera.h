#include "Vector3D.h"
#include "Transform.h"

class TPSCamera
{
public:
    Transform transform;
    float distance;  
    float angle;    
    float height;   

    TPSCamera();
    void follow(const Vector3D& targetPosition);
    void updateCamera();
};
