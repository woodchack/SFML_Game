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
	// ����������

	// Window

	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	



	// ��������� �������

	void initVariables();
	void initWindow();
public:

	// ������������ � �����������

	Game();
	virtual ~Game();

	// �������

	void update();
	void render();


	// ����������

	// ������

	const bool running() const;
};

