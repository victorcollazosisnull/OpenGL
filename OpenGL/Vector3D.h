#pragma once
class Vector3D
{
public:
    float x, y, z;

    // Constructores
    Vector3D();
    Vector3D(float x, float y, float z);

    // Operaciones básicas
    Vector3D operator+(const Vector3D& v) const;
    Vector3D operator-(const Vector3D& v) const;
    Vector3D operator*(float scalar) const;

    // Producto escalar
    float dot(const Vector3D& v) const;

    // Producto cruzado
    Vector3D cross(const Vector3D& v) const;

    // Longitud del vector
    float length() const;

    // Normalización
    void normalize();
    Vector3D normal() const;

    // Ángulo entre dos vectores
    float angleBetween(const Vector3D& v) const;
};

