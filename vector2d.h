#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D {
public:
    Vector2D(double x, double y);
    double getX() const;
    double getY() const;
    double getMagnitude() const;
    double getMagnitudeSquared() const;
    Vector2D getNormalized() const;
    void normalize();
    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator-(const Vector2D& other) const;
    Vector2D operator*(double scalar) const;
    Vector2D operator/(double scalar) const;
    Vector2D& operator+=(const Vector2D& other);
    Vector2D& operator-=(const Vector2D& other);
    Vector2D& operator*=(double scalar);
    Vector2D& operator/=(double scalar);
private:
    double x_;
    double y_;
};

#endif
