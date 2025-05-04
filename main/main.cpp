#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include "Application.hpp"
#include "Ball.hpp"

static constexpr const char* FONTFILE = "/usr/share/fonts/truetype/ubuntu/Ubuntu-C.ttf";
static const unsigned int WIDTH  = 800;
static const unsigned int HEIGHT = 600;

// window setup


template <typename T>
std::string to_string_with_presision(const T a_value, const int n = 1)
{
    std::ostringstream out;
    out.precision(n);
    out << std::fixed << a_value;
    return out.str();
}

int main()
{
    //Application app("Balls", WIDTH, HEIGHT);
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode({WIDTH, HEIGHT}), "Bouncing Ball", sf::Style::Close);
    window.setFramerateLimit(600);

    
    Ball ball(10.0F, sf::Vector2f(100.0F, 100.0F), sf::Vector2f(1.0F, 1.0F));

   
    sf::Font font;
    if (!font.openFromFile(FONTFILE))
    {
        std::cout << "Failed to load the font file.";
        return EXIT_FAILURE;
    } else
    {
        std::cout << "Font " << font.getInfo().family << " loaded successfully.";
    }

    sf::Text text(font);
    //text.setFont(font);
    text.setCharacterSize(12);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);
    text.setString("(000.0, 000.0)");
    //float textWidth = text.getLocalBounds().size().x;
    //float textHeight = text.getLocalBounds().height;
    //text.setOrigin(textWidth / 2, textHeight / 2);

    sf::Clock clock;
    float deltaTime = 0.0f;

    //while (app.get_window().isOpen())
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        deltaTime = clock.restart().asSeconds();
        window.clear();
        //app.poll_events();
        //app.clear_screen();

        //window.clear(sf::Color::Black);
        ball.update(sf::Vector2f(WIDTH, HEIGHT), deltaTime);
        ball.render(window);

        


        // Screen draw code after here

        sf::Vector2f ballPos = ball.getPosition();

        //text.setPosition(sf::Vector2(ballPos.x, (ballPos.y - ball.getRadius()) ));
        text.setString("(" + to_string_with_presision(ballPos.x) + ", " + to_string_with_presision(ballPos.y) + ")");
        window.draw(text);

        window.display();
    }
}
