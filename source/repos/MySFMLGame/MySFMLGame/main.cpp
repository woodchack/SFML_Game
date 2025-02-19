#include <iostream>
#include "Game.h"

int main()
{
	// Init Game engine
	
	Game game();

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