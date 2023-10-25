#include "./include/vector2d.h"

#include <cmath>

Vector2D::Vector2D(double x, double y) : x_{x}, y_{y} {}

double Vector2D::getX() const { return x_; }

double Vector2D::getY() const { return y_; }

double Vector2D::getMagnitude() const { return std::sqrt(x_ * x_ + y_ * y_); }

double Vector2D::getMagnitudeSquared() const { return x_ * x_ + y_ * y_; }

Vector2D Vector2D::getNormalized() const {
    double magnitude = getMagnitude();
    return Vector2D(x_ / magnitude, y_ / magnitude);
}

void Vector2D::normalize() {
    double magnitude = getMagnitude();
    x_ /= magnitude;
    y_ /= magnitude;
}

Vector2D Vector2D::operator+(const Vector2D& other) const {
    return Vector2D(x_ + other.x_, y_ + other.y_);
}

Vector2D Vector2D::operator-(const Vector2D& other) const {
    return Vector2D(x_ - other.x_, y_ - other.y_);
}

Vector2D Vector2D::operator*(double scalar) const {
    return Vector2D(x_ * scalar, y_ * scalar);
}

Vector2D Vector2D::operator/(double scalar) const {
    return Vector2D(x_ / scalar, y_ / scalar);
}

Vector2D& Vector2D::operator+=(const Vector2D& other) {
    x_ += other.x_;
    y_ += other.y_;
    return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D& other) {
    x_ -= other.x_;
    y_ -= other.y_;
    return *this;
}

Vector2D& Vector2D::operator*=(double scalar) {
    x_ *= scalar;
    y_ *= scalar;
    return *this;
}

Vector2D& Vector2D::operator/=(double scalar) {
    x_ /= scalar;
    y_ /= scalar;
    return *this;
}
