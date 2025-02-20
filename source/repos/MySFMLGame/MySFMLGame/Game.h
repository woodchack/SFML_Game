#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <random>

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

// ������������ ����������� ��� ��������
enum directions {
	UP,         // �����
	RIGHT,      // ������
	DOWN,       // ����
	LEFT,       // �����
	LEFT_UP,    // �����-�����
	RIGHT_UP,   // ������-�����
	RIGHT_DOWN, // ������-����
	LEFT_DOWN   // �����-����
};

class Game
{
private:
	// ����������

	// Window

	sf::RenderWindow* window;
	sf::VideoMode videoMode;


	// ������� ������


	int points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	unsigned int maxEnemies;
	unsigned int countEnemies;

	// ������� �������
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;
	



	// ��������� �������

	void initVariables();
	void initWindow();
	void initEnemies();

	// ������� ����

	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

public:

	// ������������ � �����������

	Game();
	virtual ~Game();

	// �������

	void spawnEnemy();
	void pollEvents();
	void updateMousePosition();
	void updateEnemies();
	void update();
	void renderEnemies();
	void render();


	// ����������

	unsigned int width = 800;
	unsigned int height = 600;

	// ������

	const bool windowIsRunning() const;
};

