#include "./include/vector2d.h"

#include <cmath>

Vector2D::Vector2D()
	: x_(0), y_(0)
{
}

Vector2D::Vector2D(uint32_t x, uint32_t y)
	: x_{x}, y_{y}
{
}

Vector2D::Vector2D(uint32_t scalar)
	: x_(scalar), y_(scalar)
{
}

uint32_t Vector2D::getMagnitude() const
{
	return (uint32_t)std::sqrt((float)(x_ * x_ + y_ * y_));
}

uint32_t Vector2D::getMagnitudeSquared() const
{
	return x_ * x_ + y_ * y_;
}

Vector2D Vector2D::getNormalized() const
{
	uint32_t magnitude = getMagnitude();
    return {x_ / magnitude, y_ / magnitude};
}

void Vector2D::normalize()
{
	uint32_t magnitude = getMagnitude();
    x_ /= magnitude;
    y_ /= magnitude;
}

Vector2D Vector2D::operator+(const Vector2D& other) const
{
    return {x_ + other.x_, y_ + other.y_};
}

Vector2D Vector2D::operator-(const Vector2D& other) const
{
    return {x_ - other.x_, y_ - other.y_};
}

Vector2D Vector2D::operator*(uint32_t scalar) const
{
    return {x_ * scalar, y_ * scalar};
}

Vector2D Vector2D::operator/(uint32_t scalar) const
{
    return {x_ / scalar, y_ / scalar};
}

Vector2D& Vector2D::operator+=(const Vector2D& other)
{
    x_ += other.x_;
    y_ += other.y_;
    return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D& other)
{
    x_ -= other.x_;
    y_ -= other.y_;
    return *this;
}

Vector2D& Vector2D::operator*=(uint32_t scalar)
{
    x_ *= scalar;
    y_ *= scalar;
    return *this;
}

Vector2D& Vector2D::operator/=(uint32_t scalar)
{
    x_ /= scalar;
    y_ /= scalar;
    return *this;
}

bool Vector2D::operator==(const Vector2D& other) const
{
	return x_ == other.x_ && y_ == other.y_;
}

bool Vector2D::operator!=(const Vector2D& other) const
{
	return x_ != other.x_ || y_ != other.y_;
}
