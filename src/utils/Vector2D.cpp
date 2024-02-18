#include "../../include/utils/Vector2D.h"
#include <cmath>

// Accessors
float Vector2D::getX() const { return m_x; }
float Vector2D::getY() const { return m_y; }

// Mutators
void Vector2D::setX(float x) { m_x = x; }
void Vector2D::setY(float y) { m_y = y; }

// Other methods
float Vector2D::magnitude() const {
    return sqrt(m_x * m_x + m_y * m_y);
}

Vector2D Vector2D::normalize() const {
    float mag = magnitude();
    return Vector2D(m_x / mag, m_y / mag);
}

float Vector2D::dotProduct(const Vector2D& v) const {
    return m_x * v.m_x + m_y * v.m_y;
}

float Vector2D::crossProduct(const Vector2D& v) const {
    return m_x * v.m_y - m_y * v.m_x; // Returns a scalar
}

// Overloaded operators
Vector2D& Vector2D::operator+=(const Vector2D& v) {
    m_x += v.m_x;
    m_y += v.m_y;
    return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D& v) {
    m_x -= v.m_x;
    m_y -= v.m_y;
    return *this;
}

Vector2D& Vector2D::operator*=(float scalar) {
    m_x *= scalar;
    m_y *= scalar;
    return *this;
}

Vector2D& Vector2D::operator/=(float scalar) {
    m_x /= scalar;
    m_y /= scalar;
    return *this;
}

Vector2D operator+(const Vector2D& v1, const Vector2D& v2) {
    return Vector2D(v1.m_x + v2.m_x, v1.m_y + v2.m_y);
}

Vector2D operator-(const Vector2D& v1, const Vector2D& v2) {
    return Vector2D(v1.m_x - v2.m_x, v1.m_y - v2.m_y);
}

Vector2D operator*(const Vector2D& v, float scalar) {
    return Vector2D(v.m_x * scalar, v.m_y * scalar);
}

Vector2D operator/(const Vector2D& v, float scalar) {
    return Vector2D(v.m_x / scalar, v.m_y / scalar);
}

bool operator==(const Vector2D& v1, const Vector2D& v2) {
    return v1.m_x == v2.m_x && v1.m_y == v2.m_y;
}

bool operator!=(const Vector2D& v1, const Vector2D& v2) {
    return !(v1 == v2);
}
