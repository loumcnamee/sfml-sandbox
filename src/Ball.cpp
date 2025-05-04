#include "Ball.hpp"

Ball::Ball(float radius, sf::Vector2f initialPosition, sf::Vector2f initialSpeed)
    : position(initialPosition)
    , speed(initialSpeed)
    , radius(radius)
    , movingRight(true)
    , movingDown(true)
{
    shape.setRadius(radius);
    shape.setPosition(position);
}

void Ball::update(const sf::Vector2f& bounds, float deltaT) {
    // Check boundaries and update direction
    if (position.x > bounds.x - (radius * 2) || position.x < 0) {
        movingRight = !movingRight;
    }
    if (position.y > bounds.y - (radius * 2) || position.y < 0) {
        movingDown = !movingDown;
    }

    // Update position based on direction
    position.x += movingRight ? speed.x : -speed.x;
    position.y += movingDown ? speed.y : -speed.y;

    // Update shape position
    shape.setPosition(position);
}

void Ball::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

void Ball::setFillColor(const sf::Color& color) {
    shape.setFillColor(color);
}

void Ball::render(sf::RenderWindow &window) {
    shape.setFillColor(sf::Color::Yellow);
    window.draw(shape);
}