#include "Game.h"

// Приватные функции



void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "Game", sf::Style::Titlebar | sf::Style::Close);
}


// Конструкторы и Деструкторы


Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

	




// Публичные Функции

// Доступ

void Game::update()
{
}

void Game::render()
{
}


 // Публичные переменные
 
 // Доступ
const bool Game::running() const
{
	
}


