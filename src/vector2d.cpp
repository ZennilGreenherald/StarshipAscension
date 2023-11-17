#include "./include/vector2d.h"

#include <cmath>

Vector2D::Vector2D()
	: x(0), y(0)
{
}

Vector2D::Vector2D(const int32_t x, const int32_t y)
	: x{x}, y{y}
{
}

Vector2D::Vector2D(const int32_t scalar)
	: x(scalar), y(scalar)
{
}

int32_t Vector2D::getMagnitude() const
{
	return static_cast<int32_t>(std::sqrt(static_cast<float>(x * x + y * y)));
}

int32_t Vector2D::getMagnitudeSquared() const
{
	return x * x + y * y;
}

Vector2D Vector2D::getNormalized() const
{
	const int32_t magnitude = getMagnitude();
    return {x / magnitude, y / magnitude};
}

void Vector2D::normalize()
{
	const int32_t magnitude = getMagnitude();
    x /= magnitude;
    y /= magnitude;
}

Vector2D Vector2D::operator+(const Vector2D& other) const
{
    return {x + other.x, y + other.y};
}

Vector2D Vector2D::operator-(const Vector2D& other) const
{
    return {x - other.x, y - other.y};
}

Vector2D Vector2D::operator*(const int32_t scalar) const
{
    return {x * scalar, y * scalar};
}

Vector2D Vector2D::operator/(const int32_t scalar) const
{
    return {x / scalar, y / scalar};
}

Vector2D& Vector2D::operator+=(const Vector2D& other)
{
    x += other.x;
    y += other.y;
    return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D& other)
{
    x -= other.x;
    y -= other.y;
    return *this;
}

Vector2D& Vector2D::operator*=(const int32_t scalar)
{
    x *= scalar;
    y *= scalar;
    return *this;
}

Vector2D& Vector2D::operator/=(const int32_t scalar)
{
    x /= scalar;
    y /= scalar;
    return *this;
}

bool Vector2D::operator==(const Vector2D& other) const
{
	return x == other.x && y == other.y;
}

bool Vector2D::operator!=(const Vector2D& other) const
{
	return x != other.x || y != other.y;
}
