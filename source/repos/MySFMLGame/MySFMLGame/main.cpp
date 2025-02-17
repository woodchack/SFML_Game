#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	unsigned int width = 640;
	unsigned int height = 360;
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({ width,height }), "Game");

	while (window->isOpen())
	{
		while (const std::optional event = window->pollEvent()) 
		{
			if (event->is<sf::Event::Closed>())
			{
				window->close();
			}
		}

		//Render

		window->clear(sf::Color(0xFF8800FF));

		//Drawing

		window->display();
	}

	delete window;

	return 0;
}