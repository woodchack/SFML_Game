#include "Game.h"

// ��������� �������



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


// ������������ � �����������


Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

	




// ��������� �������

// ������

void Game::update()
{
}

void Game::render()
{
}


 // ��������� ����������
 
 // ������
const bool Game::running() const
{
	
}


