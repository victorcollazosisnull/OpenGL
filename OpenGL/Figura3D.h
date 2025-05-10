#pragma once
#include "Figura.h"
#include "Transform.h"
class Figura3D : public Figura
{
public:
    Transform transform;
	Figura3D();

    virtual void Draw() = 0; 

    void setTranslation(const Vector3D& t) { transform.translate(t); }
    void setRotation(float angle, const Vector3D& axis) { transform.rotate(angle, axis); }
    void setScale(const Vector3D& s) { transform.scale(s); }
};

