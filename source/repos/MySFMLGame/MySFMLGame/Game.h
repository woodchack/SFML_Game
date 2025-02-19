#pragma once


#include <iostream>


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
	sf::Event ev;
	



	// Приватные функции

	void initVariables();
	void initWindow();
public:

	// Конструкторы и Деструкторы

	Game();
	virtual ~Game();

	// Функции

	void update();
	void render();


	// Переменные

	// Доступ

	const bool running() const;
};

