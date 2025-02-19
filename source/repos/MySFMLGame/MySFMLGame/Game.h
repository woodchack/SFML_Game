#pragma once


#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>


class Game
{
private:
	// Переменные

	// Window

	sf::RenderWindow* window;
	sf::VideoMode videoMode;
//	sf::Event event;
	
	



	// Приватные функции

	void initVariables();
	void initWindow();

public:

	// Конструкторы и Деструкторы

	Game();
	virtual ~Game();

	// Функции


	void pollEvents();
	void update();
	void render();


	// Переменные

	// Доступ

	const bool windowIsRunning() const;
};

