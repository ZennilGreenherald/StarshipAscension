#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <algorithm>
#include <cmath>

class Vector2D {
  public:
    float x;  // x-coordinate
    float y;  // y-coordinate

    // Constructor
    Vector2D(float x = 0, float y = 0) : m_x(x), m_y(y) {}

    // Accessors
    float getX() const;
    float getY() const;

    // Mutators
    void setX(float x);
    void setY(float y);

    // Other methods
    float magnitude() const;
    Vector2D normalize() const;
    float dotProduct(const Vector2D& v) const;
    Vector2D crossProduct(
        const Vector2D& v) const;  // Corrected return type to Vector2D

    // Overloaded operators
    Vector2D& operator+=(const Vector2D& v);
    Vector2D& operator-=(const Vector2D& v);
    Vector2D& operator*=(float scalar);
    Vector2D& operator/=(float scalar);

    friend Vector2D operator+(const Vector2D& v1, const Vector2D& v2);
    friend Vector2D operator-(const Vector2D& v1, const Vector2D& v2);
    friend Vector2D operator*(const Vector2D& v, float scalar);
    friend Vector2D operator/(const Vector2D& v, float scalar);

    friend bool operator==(const Vector2D& v1, const Vector2D& v2);
    friend bool operator!=(const Vector2D& v1, const Vector2D& v2);

  private:
    float m_x;
    float m_y;
};

#endif  // VECTOR2D_H
