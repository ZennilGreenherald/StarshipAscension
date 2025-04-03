#ifndef POSITION_H
#define POSITION_H

#include <cmath>  // For sqrt, pow, etc.

class Position {
  public:
    Position();                           // Default constructor
    Position(float x, float y, float z);  // Custom constructor
    ~Position();                          // Destructor

    float getX() const;
    float getY() const;
    float getZ() const;
    void setX(float x);
    void setY(float y);
    void setZ(float z);

    // Additional functions
    float distanceTo(const Position& other) const;  // Calculate distance to another position
    Position operator+(const Position& other) const; // Add two positions
    Position operator-(const Position& other) const; // Subtract two positions
    bool operator==(const Position& other) const;    // Compare two positions

    void translate(float dx, float dy, float dz);    // Move the position by dx, dy, dz
    void reset();                                     // Reset position to (0, 0, 0)

  private:
    float x;
    float y;
    float z;
};

#endif  // POSITION_H
