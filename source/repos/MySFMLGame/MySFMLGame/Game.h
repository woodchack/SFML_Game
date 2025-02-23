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

// Перечисление направлений для анимации
enum directions {
	UP,         // Вверх
	RIGHT,      // Вправо
	DOWN,       // Вниз
	LEFT,       // Влево
	LEFT_UP,    // Влево-вверх
	RIGHT_UP,   // Вправо-вверх
	RIGHT_DOWN, // Вправо-вниз
	LEFT_DOWN   // Влево-вниз
};

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

	// Враги

	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;
	
	//Character
	sf::Sprite character;

	sf::Texture characterTexture;

	

	sf::IntRect dir[8];

	// Приватные функции
	int returnError();
	void initVariables();
	void initWindow();
	void initEnemies();
	void initChar();

	// Позиция мыши

	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

public:

	// Конструкторы и Деструкторы

	Game();
	virtual ~Game();

	// Функции
	void characterUpdate();
	void spawnEnemy();
	void pollEvents();
	void updateMousePosition();
	void updateEnemies();
	void update();
	void characterRender();
	void renderEnemies();
	void render();
	



	// Переменные

	unsigned int width = 800;
	unsigned int height = 600;

	// Доступ

	const bool windowIsRunning() const;
};

