#ifndef MOON_H
#define MOON_H

#include <string>

class Moon {
public:
    // Constructor
    Moon(const std::string& name, double distanceFrom, double gravity);

    // Getters
    std::string getName() const;
    double getDistanceFrom() const;
    double getGravity() const;

    // Setters
    void setName(const std::string& name);
    void setDistanceFrom(double distanceFrom);
    void setGravity(double gravity);

private:
    std::string m_name;
    double m_distanceFrom;
    double m_gravity;
};

#endif // MOON_H
