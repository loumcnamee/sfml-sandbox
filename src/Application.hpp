#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include <SFML/Graphics.hpp>

class Application
{
	public:
		Application(const std::string &title, unsigned int width, unsigned int height);
		virtual ~Application();

		void poll_events();
		void clear_screen();

	private:
		sf::RenderWindow window;

	public:
		sf::RenderWindow& get_window();
};

#endif