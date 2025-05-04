#include <SFML/Graphics.hpp>
#include <iostream>

#include "Application.hpp"

Application::Application(const std::string &title, unsigned int width, unsigned int height) :
	window(sf::VideoMode({width, height}), title, sf::Style::Close | sf::Style::Titlebar)
{
    //auto window = sf::RenderWindow(sf::VideoMode({800u, 600u}), "CMake SFML Project");
    window.setFramerateLimit(144);
    // screen bounds
    //const auto BOUNDS = static_cast<sf::Vector2f>(window.getSize());
}

Application::~Application()
{
}

void Application::poll_events()
{
	const std::optional event  = window.pollEvent();
    if (event->is<sf::Event::Closed>())
    {
        window.close();
    }
    window.clear();
    window.display();
	
}

void Application::clear_screen()
{
	window.display();
	window.clear(sf::Color::Black);
}

sf::RenderWindow& Application::get_window()
{
	return window;
}