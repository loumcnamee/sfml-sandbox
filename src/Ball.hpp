#pragma once
#include <SFML/Graphics.hpp>

class Ball {
private:
    sf::Vector2f position;
    sf::Vector2f speed;
    float radius;
    sf::CircleShape shape;
    bool movingRight;
    bool movingDown;

public:
    Ball(float radius = 10.0f, sf::Vector2f initialPosition = sf::Vector2f(0.0f, 0.0f), 
        sf::Vector2f initialSpeed = sf::Vector2f(10.0f, 10.0f));
    
    void update(const sf::Vector2f& bounds, float deltaT);
    void draw(sf::RenderWindow& window);

    void render(sf::RenderWindow &window);
    
    const sf::Vector2f& getPosition() const { return position; }
    float getRadius() const { return radius; }
    void setFillColor(const sf::Color& color);
};