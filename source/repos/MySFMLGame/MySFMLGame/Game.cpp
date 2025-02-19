#include "Game.h"

// ��������� �������



void Game::initVariables()
{
	window = nullptr;
}

void Game::initWindow()
{
	videoMode = sf::VideoMode::getDesktopMode();
	window = new sf::RenderWindow(videoMode, "Game", sf::Style::Titlebar | sf::Style::Close);
}


// ������������ � �����������


Game::Game()
{
	initVariables();
	initWindow();

}

Game::~Game()
{
	delete window;
}

	




// ��������� �������
void Game::pollEvents()
{
	
	while (const std::optional event = window->pollEvent())
	{

		if (event->is<sf::Event::Closed>())
		{

			window->close();

		} else
			if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
			{

				if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
				{
					window->close();
				}

			}

	}
		
			
		
	}


// ������



void Game::update()
{
	pollEvents();
}

void Game::render()
{
	// Render objects here:
	

	window->clear(sf::Color(255,0,0,255));

	// Draw game here:

	window->display();
}


 // ��������� ����������

 // ������
const bool Game::windowIsRunning() const
{
	return window->isOpen();
}


