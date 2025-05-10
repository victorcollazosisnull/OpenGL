#include "Vector3D.h"
#include <math.h>
Vector3D::Vector3D() : x(0), y(0), z(0) {}

Vector3D::Vector3D(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3D Vector3D::operator+(const Vector3D& v) const {
    return Vector3D(x + v.x, y + v.y, z + v.z);
}
Vector3D Vector3D::operator-(const Vector3D& v) const {
    return Vector3D(x - v.x, y - v.y, z - v.z);
}
Vector3D Vector3D::operator*(float scalar) const {
    return Vector3D(x * scalar, y * scalar, z * scalar);
}
float Vector3D::dot(const Vector3D& v) const {
    return (x * v.x) + (y * v.y) + (z * v.z);
}
Vector3D Vector3D::cross(const Vector3D& v) const {
    return Vector3D(
        (y * v.z - z * v.y),
        (z * v.x - x * v.z),
        (x * v.y - y * v.x)
    );
}
float Vector3D::length() const {
    return sqrt(x * x + y * y + z * z);
}
void Vector3D::normalize() {
    float len = length();
    if (len != 0) {
        x /= len;
        y /= len;
        z /= len;
    }
}
Vector3D Vector3D::normal() const {
    float len = length();
    if (len != 0) {
        return Vector3D(x / len, y / len, z / len);
    }
    return Vector3D(0, 0, 0);
}
float Vector3D::angleBetween(const Vector3D& v) const {
    float dotProduct = this->dot(v);
    float magnitudes = this->length() * v.length();
    if (magnitudes == 0) return 0.0f; 
    return acos(dotProduct / magnitudes);
}