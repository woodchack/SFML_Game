#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <cmath>
#include <sstream>

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


	//loseWindow
	sf::VideoMode videoLoseMode;
	sf::RenderWindow* loseWindow;
	


	// Игровая логика

	bool isPaused;
	int points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	unsigned int maxEnemies;
	unsigned int countEnemies;



	sf::Font font;
	sf::Text textPoints;
	sf::Text loseLevelText;
	// Игровые объекты

	sf::Texture backgroundTexture;
	sf::RectangleShape background;

	// Враги

	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;
	sf::Texture enemyTexture;
	
	//Character
	sf::Sprite character;

	sf::Texture characterTexture;

	

	sf::IntRect dir[8];

	// Приватные функции
	int returnError();
	void initVariables();
	void initWindow();
	void initBackground();
	void initEnemies();
	void initChar();
	void initFonts();
	void initFontsLoseWindow();
	void initLoseWindow();

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
	void pollLoseEvent();
	void updateMousePosition();
	void updateLoseWindow();
	void updateEnemies();
	void updateFonts();
	void update();
	void renderBackground();
	void characterRender();
	void renderEnemies();
	void renderFonts();
	void renderLoseWindow();
	void render();
	



	// Переменные

	unsigned int width = 800;
	unsigned int height = 600;

	// Доступ

	const bool windowIsRunning() const;
};

