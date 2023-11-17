#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <cstdint>

class Vector2D
{
public:
	int32_t x;
	int32_t y;

    Vector2D(const int32_t x, const int32_t y);
    explicit Vector2D(const int32_t scalar);
    Vector2D();

	int32_t getMagnitude() const;
	int32_t getMagnitudeSquared() const;
    Vector2D getNormalized() const;
    void normalize();
    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator-(const Vector2D& other) const;
    Vector2D operator*(const int32_t scalar) const;
    Vector2D operator/(const int32_t scalar) const;
    Vector2D& operator+=(const Vector2D& other);
    Vector2D& operator-=(const Vector2D& other);
    Vector2D& operator*=(const int32_t scalar);
    Vector2D& operator/=(const int32_t scalar);
	bool operator==(const Vector2D& other) const;
	bool operator!=(const Vector2D& other) const;
};

#endif
