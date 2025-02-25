#include "Game.h"

// Приватные функции



int Game::returnError()
{
	return -1;
}

void Game::initVariables()
{
	window = nullptr;


	// Игровая логика

	points = 0;

	enemySpawnTimerMax = 10.f;
	enemySpawnTimer = enemySpawnTimerMax;
	
	countEnemies = 0;
	maxEnemies = 5;


	// char directions 

	sf::IntRect dir[8];
	dir[0] = sf::IntRect({ {116, 0}, {116, 116} });     // up
	dir[1] = sf::IntRect({ {232, 116}, {116, 116} });   // right
	dir[2] = sf::IntRect({ {116, 232}, {116, 116} });   // down
	dir[3] = sf::IntRect({ {0, 116}, {116, 116} });     // left
	dir[4] = sf::IntRect({ {0, 0}, {116, 116} });       // left_up
	dir[5] = sf::IntRect({ {232, 0}, {116, 116} });     // right_up
	dir[6] = sf::IntRect({ {232, 232}, {116, 116} });  // right_down
	dir[7] = sf::IntRect({ {0, 232}, {116, 116} });     // left_down

	// Fonts

	
	
	


}

void Game::initWindow()
{
	width = 800;
	height = 600;

	sf::VideoMode videoMode({width, height});

	if(!backgroundTexture.loadFromFile("Sprites/back.png")) {
		std::cerr << "ERROR::COULD NOT LOAD TEXTURE::Sprites/back.png";
		returnError();
	}
	background.setTexture(backgroundTexture);
	background.setScale(sf::Vector2f(width, height));

	window = new sf::RenderWindow(videoMode, "Game", sf::Style::Titlebar | sf::Style::Close);

	window->setFramerateLimit(60);
}

void Game::initEnemies()
{
	if (!enemyTexture.loadFromFile("Sprites/fish.png")) {
		std::cerr << "ERROR::COULD NOT LOAD TEXTURE::Sprites/fish.png";
		returnError();
	}

	enemy.setPosition(sf::Vector2f(width / 2, height / 2));
	enemy.setSize(sf::Vector2f(100.f, 100.f));
	enemy.setScale(sf::Vector2f(0.5f, 0.5f));
	enemy.setTexture(&enemyTexture);
}

void Game::initChar()
{
	
	if (!characterTexture.loadFromFile("Sprites/ship.png")) {
		std::cerr << "ERROR::COULD NOT LOAD TEXTURE::Sprites/ship.png";
		returnError();
	}
	// Массив прямоугольников для разных направлений (текстурный атлас)

	dir[0] = sf::IntRect({ {116, 0}, {116, 116} });     // up
	dir[1] = sf::IntRect({ {232, 116}, {116, 116} });   // right
	dir[2] = sf::IntRect({ {116, 232}, {116, 116} });   // down
	dir[3] = sf::IntRect({ {0, 116}, {116, 116} });     // left
	dir[4] = sf::IntRect({ {0, 0}, {116, 116} });       // left_up
	dir[5] = sf::IntRect({ {232, 0}, {116, 116} });     // right_up
	dir[6] = sf::IntRect({ {235, 235}, {116, 116} });  // right_down
	dir[7] = sf::IntRect({ {0, 235}, {116, 116} });     // left_down

	character.setTexture(characterTexture); // Установка текстуры
	characterTexture.setSmooth(true);
	character.setTextureRect(dir[RIGHT]);
	character.setOrigin(sf::Vector2f(116, 116));
	character.setPosition(sf::Vector2f(width / 2, height / 2));


}

void Game::initFonts()
{
	
	if (!font.openFromFile("Fonts/Pixelizer.ttf"))
	{
		std::cerr << "Error::Failed to load Fonts/Pixelizer.ttf";
		returnError();
	}
	textPoints.setFont(font);
	textPoints.setCharacterSize(24);
	textPoints.setFillColor(sf::Color::Black);
	textPoints.setPosition(sf::Vector2f(0.f, 0.f));
	textPoints.setString("Score = 0");
	
	
	
}


// Конструкторы и Деструкторы


Game::Game() : character(characterTexture), background(backgroundTexture), textPoints(font)
{
	initVariables();
	initWindow();
	initFonts();
	initEnemies();
	initChar();
	

}

Game::~Game()
{
	delete window;
}

	

// Публичные Функции


void Game::spawnEnemy() {
	// Получаем размеры окна и врага
	
	enemy.setPosition(sf::Vector2f(
		static_cast<float>(rand() % static_cast<int>(window->getSize().x - enemy.getSize().x)),
		0.f
	));


	// Спавним врага

	

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

	// Обновление позиции мыши
	// Относительно окна

	mousePosWindow = sf::Mouse::getPosition(*window);

	mousePosView = window->mapPixelToCoords(mousePosWindow);


	std::cout << "Mouse pos = " << sf::Mouse::getPosition(*window).x << " " << sf::Mouse::getPosition(*window).y << "\n";
}




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
	// Перемещение вражин
	for (int i = 0; i < enemies.size(); ++i)
	{
		enemies[i].move(sf::Vector2f(0.f, 2.f));


		// Проверка пересечение

		
			if (enemies[i].getGlobalBounds().findIntersection(character.getGlobalBounds()))
			{
				enemies[i].setPosition(sf::Vector2f(
					static_cast<float>(rand() % static_cast<int>(window->getSize().x - enemy.getSize().x)),
					0.f
				));
				++points;
				updateFonts();
				std::cout << points << "\n";
			}
		

		if (enemies[i].getPosition().y > window->getSize().y)
		{
			enemies[i].setPosition(sf::Vector2f(
				static_cast<float>(rand() % static_cast<int>(window->getSize().x - enemy.getSize().x)),
				0.f
			));
		}
	}
}
void Game::characterUpdate()
{
	// Обработка движения

	// Диагональные направления (имеют приоритет над основными)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) &&
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		character.move({ -4.f, -4.f });
		character.setTextureRect(dir[LEFT_UP]);
	} else
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) &&
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		character.move({ 4.f, -4.f });
		character.setTextureRect(dir[RIGHT_UP]);
	} else
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) &&
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		character.move({ 4.f, 4.f });
		character.setTextureRect(dir[RIGHT_DOWN]);
	} else
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) &&
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		character.move({ -4.f, 4.f });
		character.setTextureRect(dir[LEFT_DOWN]);
	} else

		  // Основные направления
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		character.move({ 5.f, 0.0f });
		character.setTextureRect(dir[RIGHT]);
	} else
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		character.move({ 0.0f, -5.f }); 
		character.setTextureRect(dir[UP]);
	} else
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		character.move({ 0.0f, 5.f });
		character.setTextureRect(dir[DOWN]);
	} else
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		character.move({ -5.f, 0.0f });
		character.setTextureRect(dir[LEFT]);
	}

	
}
void Game::updateFonts()
{
	
	std::ostringstream scorePoints;
	scorePoints << "Score = " << points;
	textPoints.setString(scorePoints.str());
}


void Game::update()
{
	pollEvents();

//	updateMousePosition();


	updateEnemies();

	characterUpdate();
	
}


// Render функции

void Game::renderEnemies()
{
	// Render вражин
	for (auto& e : this->enemies)
	{
		window->draw(e);
	}
	
}
void Game::characterRender()
{
	window->draw(character);
}
void Game::renderFonts()
{
	window->draw(textPoints);
}


void Game::render()
{
	// Render objects here:
	
	

	window->clear(sf::Color::White);

	// Draw game here:
	renderFonts();
	characterRender();
	renderEnemies();
	
	
	
	window->display();
}


 // Публичные переменные

 // Доступ
const bool Game::windowIsRunning() const
{
	return window->isOpen();
}


