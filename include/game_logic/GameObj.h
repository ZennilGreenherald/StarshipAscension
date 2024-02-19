#ifndef GAME_OBJ_H
#define GAME_OBJ_H

#include <string>
#include "../../include/utils/Vector2D.h"

class GameObj {
public:
    GameObj(const std::string& name, const Vector2D& position, double size);
    virtual ~GameObj();

    // Getters
    std::string getName() const;
    Vector2D getPosition() const;
    double getSize() const;

    // Setters
    void setName(const std::string& name);
    void setPosition(const Vector2D& position);
    void setSize(double size);

    // Virtual methods that can be overridden by derived classes
    virtual void update() =  0;
    virtual void render() =  0;

protected:
    std::string name;
    Vector2D position;
    double size;
};

#endif // GAME_OBJ_H
