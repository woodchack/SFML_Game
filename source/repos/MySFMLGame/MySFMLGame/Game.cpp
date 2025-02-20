#include "Game.h"

// ��������� �������



void Game::initVariables()
{
	window = nullptr;


	// ������� ������

	points = 0;
	enemySpawnTimerMax = 1000.f;
	enemySpawnTimer = enemySpawnTimerMax;
	countEnemies = 0;
	maxEnemies = 5;


}

void Game::initWindow()
{
	width = 800;
	height = 600;

	sf::VideoMode videoMode({width, height});

	window = new sf::RenderWindow(videoMode, "Game", sf::Style::Titlebar | sf::Style::Close);

	window->setFramerateLimit(144);
}

void Game::initEnemies()
{
	enemy.setPosition(sf::Vector2f(width / 2, height / 2));
	enemy.setSize(sf::Vector2f(100.f, 100.f));
	enemy.setScale(sf::Vector2f(0.5f, 0.5f));
	enemy.setFillColor(sf::Color::Red);
	enemy.setOutlineColor(sf::Color::White);
	enemy.setOutlineThickness(4.f);
}


// ������������ � �����������


Game::Game()
{
	initVariables();
	initWindow();
	initEnemies();

}

Game::~Game()
{
	delete window;
}

	

// ��������� �������
void Game::spawnEnemy() {
	// �������� ������� ���� � �����
	
	enemy.setPosition(sf::Vector2f(
		static_cast<float>(rand() % static_cast<int>(window->getSize().x - enemy.getSize().x)),
		0.f
	));


	// ������� �����

	enemy.setFillColor(sf::Color::Green);

	enemies.push_back(enemy);
}

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



void Game::updateMousePosition()
{

	// ���������� ������� ����
	// ������������ ����

	mousePosWindow = sf::Mouse::getPosition(*window);


	std::cout << "Mouse pos = " << sf::Mouse::getPosition(*window).x << " " << sf::Mouse::getPosition(*window).y << "\n";
}


// ������

void Game::updateEnemies()
{
	if (countEnemies < maxEnemies)
	{
		if (enemySpawnTimer >= enemySpawnTimerMax)
		{
			spawnEnemy();
			enemySpawnTimer = 0.f;
			countEnemies++;
		}
		else
		{
			enemySpawnTimer += 1.f;
		}
	}

	for (auto &e :this->enemies)
	{
		e.move(sf::Vector2f(0.f, 2.f));
	}

}

void Game::update()
{
	pollEvents();

	updateMousePosition();

	updateEnemies();
	
}


// Render �������

void Game::renderEnemies()
{
	// Render ������
	for (auto& e : this->enemies)
	{
		window->draw(e);
	}
	
}



void Game::render()
{
	// Render objects here:
	
	

	window->clear(sf::Color::Blue);

	// Draw game here:
	renderEnemies();

	window->display();
}


 // ��������� ����������

 // ������
const bool Game::windowIsRunning() const
{
	return window->isOpen();
}


