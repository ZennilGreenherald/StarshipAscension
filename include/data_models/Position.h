#ifndef POSITION_H
#define POSITION_H

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

  private:
    float x;
    float y;
    float z;
};

#endif
