#pragma once

#include <SFML/Graphics.hpp>

class Particle: public sf::CircleShape {
public:
    Particle(const float radius, const sf::Vector2f initialPosition);
    ~Particle();

    const size_t getResultantVelocity();

    void update(const sf::Int64 deltaTime);
    void moveToTheHorizontal(const double velocity, const double radians);

private:
    double horizontalVelocity = 0;
    double verticalVelocity = 0;
};
