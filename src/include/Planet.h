#ifndef PLANET_H
#define PLANET_H

#include <string>

class Planet {

public:
  // Constructor
  Planet(double size);

  // Getter method
  double getSize() const;

  // Setter method
  void setSize(double size);

private:
  double size;
};

// Constructor implementation
Planet::Planet(double size) : size(size) {}

// Getter method implementation
double Planet::getSize() const {
    return size;
}

// Setter method implementation
void Planet::setSize(double size) {
    this->size = size;
}

#endif // PLANET_H
