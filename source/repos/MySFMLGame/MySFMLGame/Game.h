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


class Game
{
private:
	// Переменные

	// Window

	sf::RenderWindow* window;
	sf::VideoMode videoMode;


	// Игровая логика


	int points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	unsigned int maxEnemies;
	unsigned int countEnemies;

	// Игровые объекты
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;



	// Приватные функции

	void initVariables();
	void initWindow();
	void initEnemies();

	// Позиция мыши

	sf::Vector2i mousePosWindow;

public:

	// Конструкторы и Деструкторы

	Game();
	virtual ~Game();

	// Функции

	void spawnEnemy();
	void pollEvents();
	void updateMousePosition();
	void updateEnemies();
	void update();
	void renderEnemies();
	void render();


	// Переменные

	unsigned int width = 800;
	unsigned int height = 600;

	// Доступ

	const bool windowIsRunning() const;
};

