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
	enemySpeed = 2.f;
	
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

	window = new sf::RenderWindow(videoMode, "Game", sf::Style::Titlebar | sf::Style::Close);

	window->setFramerateLimit(60);
}

void Game::initBackground()
{
	if (!backgroundTexture.loadFromFile("Sprites/back.png"))
	{
		std::cerr << "ERROR::COULD NOT LOAD TEXTURE::Sprites/back.png";
		returnError();
	}
	background.setTexture(&backgroundTexture);
	background.setSize(sf::Vector2f(width, height));
}

void Game::initEnemies()
{
	if (!enemyTexture.loadFromFile("Sprites/fish.png")) {
		std::cerr << "ERROR::COULD NOT LOAD TEXTURE::Sprites/fish.png";
		returnError();
	}

	
	enemy.setSize(sf::Vector2f(100.f, 100.f));
	enemy.setScale(sf::Vector2f(0.5f, 0.5f));
	enemy.setTexture(&enemyTexture);
	enemy.setPosition(sf::Vector2f(width / 2, height / 2));
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
void Game::initFontsLoseWindow()
{
	loseLevelText.setFont(font);
	loseLevelText.setCharacterSize(30);
	loseLevelText.setFillColor(sf::Color::White);
}

void Game::initQuitButtonText()
{
	quitText.setFont(font);
	quitText.setCharacterSize(25);
	quitText.setFillColor(sf::Color::White);
	
}

void Game::initRestartButtonText()
{
	restartText.setFont(font);
	restartText.setCharacterSize(25);
	restartText.setFillColor(sf::Color::White);
	
}
void Game::initLoseWindow()
{
	sf::VideoMode videoLoseMode({ 450, 350});

	loseWindow = new sf::RenderWindow(videoLoseMode, "Game Over", sf::Style::None);

	loseWindow->setFramerateLimit(60);

}


void Game::initLoseButtons()
{
	quitButton.setSize(sf::Vector2f(130, 60));
	quitButton.setPosition(sf::Vector2f(70, 260));
	quitButton.setOutlineThickness(4.f);
	quitButton.setOutlineColor(sf::Color(250, 150, 100));
	quitButton.setFillColor(sf::Color::Black);


	restartButton.setSize(sf::Vector2f(130, 60));
	restartButton.setPosition(sf::Vector2f(255, 260));
	restartButton.setOutlineThickness(4.f);
	restartButton.setOutlineColor(sf::Color(250, 150, 100));
	restartButton.setFillColor(sf::Color::Black);
}


void Game::restartGame() 
{
	// Сброс игровых параметров
	points = 0;
	enemySpawnTimer = enemySpawnTimerMax;
	countEnemies = 0;
	isPaused = false;
	enemies.clear();
	window->clear();
	delete window;
	window = nullptr;
	delete loseWindow;
	loseWindow = nullptr;
	enemySpeed = 0;
	maxEnemies = 5;
	initVariables();
	initWindow();
	initBackground();
	initFonts();
	initEnemies();
	initChar();
	initLoseButtons();
	initFontsLoseWindow();
	initRestartButtonText();
	initQuitButtonText();
	
}

// Конструкторы и Деструкторы


Game::Game() : character(characterTexture), textPoints(font), loseLevelText(font), restartText(font), quitText(font)
{
	initVariables();
	initWindow();
	initBackground();
	initFonts();
	initEnemies();
	initChar();
	initLoseButtons();
	initFontsLoseWindow();
	initRestartButtonText();
	initQuitButtonText();
	

}

Game::~Game()
{
	delete window;
	if (loseWindow) {
		delete loseWindow;
	}
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
			

		}
		else
			if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
			{

				if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
				{
					window->close();
					
				}

			}
		

	}

	
}
void Game::pollLoseEvent()
{
	if (loseWindow)
	{
		while (const std::optional loseEvent = loseWindow->pollEvent())
		{

			if (loseEvent->is<sf::Event::Closed>())
			{

				loseWindow->close();


			}
			else
				if (const auto* keyPressed = loseEvent->getIf<sf::Event::KeyPressed>())
				{

					if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
					{
						loseWindow->close();

					}

				}


		}
	}
}


void Game::updateMousePosition()
{

	// Обновление позиции мыши
	// Относительно окна

	if (loseWindow && loseWindow->isOpen())
	{
		mousePosWindow = sf::Mouse::getPosition(*loseWindow);

		mousePosView = loseWindow->mapPixelToCoords(mousePosWindow);
	}
	else
	{
		mousePosWindow = sf::Mouse::getPosition(*window);

		mousePosView = window->mapPixelToCoords(mousePosWindow);
	}

//	std::cout << "Mouse pos = " << sf::Mouse::getPosition(*window).x << " " << sf::Mouse::getPosition(*window).y << "\n";
}

void Game::timer()
{
	static sf::Clock clock; 
	if (clock.getElapsedTime().asSeconds() >= 10.f)
	{
		maxEnemies++;
		enemySpeed += 0.1f;
		clock.restart(); 
	}
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
		enemies[i].move(sf::Vector2f(0.f, enemySpeed));


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
			isPaused = true;

			initLoseWindow();
			

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

void Game::buttonPressEvent()
{
	if (loseWindow && loseWindow->isOpen())
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			if (quitButton.getGlobalBounds().contains(mousePosView))
			{
				window->close(); // Корректное закрытие основного окна
				if (loseWindow) {
					loseWindow->close(); // Корректное закрытие окна поражения
				}
			}


			if (restartButton.getGlobalBounds().contains(mousePosView))
			{
			restartGame();
			}
		}
	}
}


void Game::updateLoseWindow()
{
	std::ostringstream scorePointsLW;
	scorePointsLW << "YOU LOSE!\n\n" << "Your score: " << points;

	loseLevelText.setString(scorePointsLW.str());

	restartText.setString("Restart");

	quitText.setString("Quit");
}

void Game::update()
{
	


		pollEvents();
		pollLoseEvent();
		updateMousePosition();
		timer();


		if (loseWindow && loseWindow->isOpen()) {
			updateLoseWindow();
			buttonPressEvent();
		}
		
		if (isPaused == false)
		{

			updateEnemies();
			characterUpdate();
		}
		
}


// Render функции
void Game::renderBackground()
{
	window->draw(background);
}
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

	if (loseWindow && loseWindow->isOpen()) {
		loseLevelText.setPosition(sf::Vector2f(140.f, 50.f));
		loseWindow->draw(loseLevelText);

		quitText.setPosition(sf::Vector2f(115.f, 275.f));
		loseWindow->draw(quitText);

		restartText.setPosition(sf::Vector2f(280.f, 275.f));
		loseWindow->draw(restartText);
	}
}



void Game::render()
{

	window->clear(sf::Color::White);
	renderBackground();
	characterRender();
	renderEnemies();
	renderFonts(); // Переместить сюда, чтобы основной интерфейс рисовался поверх
	window->display();

	if (loseWindow && loseWindow->isOpen()) {
		loseWindow->clear();
		loseWindow->draw(restartButton);
		loseWindow->draw(quitButton);
		renderFonts(); // Уже защищено проверкой внутри
		loseWindow->display();
	}
}

 // Публичные переменные

 // Доступ
const bool Game::windowIsRunning() const
{
	return window->isOpen();
}


