#include <SFML/Graphics.hpp>
#include "particle.hpp"

const size_t WINDOW_WIDTH = 1280;
const size_t WINDOW_HEIGHT = 720;

const float getY(const float Y) { return WINDOW_HEIGHT - Y; }

int main() {
    const char* WINDOW_TITLE = "2D Collisions";

    const double PI = 3.141592543;

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);

    Particle particle1(25.f, sf::Vector2f(150.f, getY(100.f)));
    Particle particle2(25.f, sf::Vector2f(600.f, getY(550.f)));

    sf::Clock clock;

    particle1.moveToTheHorizontal(100, PI/4);
    particle2.moveToTheHorizontal(100, (5*PI)/4);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        sf::FloatRect particle1HitBox = particle1.getGlobalBounds();
        sf::FloatRect particle2HitBox = particle2.getGlobalBounds();

        if (particle1HitBox.intersects(particle2HitBox)) {
            window.close();
        }

        sf::Int64 deltaTime = clock.getElapsedTime().asMicroseconds();
        clock.restart();

        particle1.update(deltaTime);
        particle2.update(deltaTime);

        window.clear(sf::Color::White);
        window.draw(particle1);
        window.draw(particle2);
        window.display();
    }

    return 0;
}
