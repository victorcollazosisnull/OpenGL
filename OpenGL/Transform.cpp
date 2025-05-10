#include "Transform.h"
#include "IncludeGL.h"
 

Transform::Transform() : translation(0, 0, 0), rotationAxis(0, 0, 1), rotationAngle(0), scaling(1, 1, 1) {}

void Transform::translate(const Vector3D& t) {
    translation = t;
}

void Transform::rotate(float angle, const Vector3D& axis) {
    rotationAngle = angle;
    rotationAxis = axis.normal();  
}

void Transform::scale(const Vector3D& s) {
    scaling = s;
}

void Transform::applyTransformations()
{
    glTranslatef(translation.x, translation.y, translation.z);

    glScalef(scaling.x, scaling.y, scaling.z);

    glRotatef(rotationAngle, rotationAxis.x, rotationAxis.y, rotationAxis.z);
}