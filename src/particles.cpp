#include "particle.hpp"
#include <cmath>
#include <iostream>

Particle::Particle(const float radius, const sf::Vector2f initialPosition) : sf::CircleShape(radius) {
    this->setOrigin(radius, radius);
    this->setFillColor(sf::Color(45, 40, 45));
    this->setPosition(initialPosition.x, initialPosition.y);
}

Particle::~Particle() { }

const size_t Particle::getResultantVelocity() {
    return 0;
}

void Particle::update(const sf::Int64 deltaTime) {
    const double deltaTimeInSeconds = deltaTime * 0.000001;

    const double horizontalDistance = this->horizontalVelocity * deltaTimeInSeconds;
    const double verticalDistance = this->verticalVelocity * deltaTimeInSeconds;

    // std::cout << "Horizontal Distance Travelled: " << horizontalDistance << '\n';
    // std::cout << "Vertical Distance Travelled: " << verticalDistance << '\n';

    this->move(horizontalDistance, -(verticalDistance));
}

void Particle::moveToTheHorizontal(const double velocity, const double radians) {
    this->horizontalVelocity = velocity * cos(radians);
    this->verticalVelocity = velocity * sin(radians);

    // std::cout << "Radians: " << radians << '\n';
    // std::cout << "cos(" << radians << "): " << cos(radians) << '\n';
    // std::cout << "sin(" << radians << "): " << sin(radians) << '\n';
    // std::cout << "Horizontal Velocity: " << this->horizontalVelocity << '\n';
    // std::cout << "Vertical Velocity: " << this->verticalVelocity << '\n';
}

