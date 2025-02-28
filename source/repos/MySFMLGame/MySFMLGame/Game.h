#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <cmath>
#include <sstream>
#include <chrono>
#include <thread>

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


	//loseWindow
	sf::VideoMode videoLoseMode;
	sf::RenderWindow* loseWindow;
	sf::RectangleShape restartButton;
	sf::RectangleShape quitButton;
	


	// ������� ������

	bool isPaused;
	int points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	unsigned int maxEnemies;
	unsigned int countEnemies;
	float enemySpeed;
	



	sf::Font font;
	sf::Text textPoints;
	sf::Text loseLevelText;
	sf::Text quitText;
	sf::Text restartText;

	
	// ������� �������

	sf::Texture backgroundTexture;
	sf::RectangleShape background;

	// �����

	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;
	sf::Texture enemyTexture;
	
	//Character
	sf::Sprite character;

	sf::Texture characterTexture;

	

	sf::IntRect dir[8];

	// ��������� �������
	int returnError();
	void initVariables();
	void initWindow();
	void initBackground();
	void initEnemies();
	void initChar();
	void initFonts();
	void initFontsLoseWindow();
	void initQuitButtonText();
	void initRestartButtonText();
	void initLoseWindow();
	void initLoseButtons();

	void restartGame();


	// ������� ����

	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

public:

	// ������������ � �����������

	Game();
	virtual ~Game();

	// �������

	void characterUpdate();
	void spawnEnemy();
	void pollEvents();
	void pollLoseEvent();
	void updateMousePosition();
	void updateLoseWindow();
	void updateEnemies();
	void updateFonts();
	void timer();
	void update();
	void renderBackground();
	void characterRender();
	void renderEnemies();
	void renderFonts();
	void buttonPressEvent();
	void render();
	



	// ����������

	unsigned int width = 800;
	unsigned int height = 600;

	// ������

	const bool windowIsRunning() const;
};

