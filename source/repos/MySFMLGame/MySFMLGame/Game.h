#pragma once


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
//	sf::Event event;
	
	



	// ��������� �������

	void initVariables();
	void initWindow();

public:

	// ������������ � �����������

	Game();
	virtual ~Game();

	// �������


	void pollEvents();
	void update();
	void render();


	// ����������

	// ������

	const bool windowIsRunning() const;
};

