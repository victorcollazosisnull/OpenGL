#pragma once
#include "Vector3D.h"
 
class Transform {
public:
    Transform(); 

    void translate(const Vector3D& t); 
    void rotate(float angle, const Vector3D& axis); 
    void scale(const Vector3D& s);

    void applyTransformations(); 

    Vector3D getTranslation() const { return translation; }
    Vector3D getRotationAxis() const { return rotationAxis; }
    float getRotationAngle() const { return rotationAngle; }

private:
    Vector3D translation;
    Vector3D rotationAxis;
    float rotationAngle;
    Vector3D scaling;
};