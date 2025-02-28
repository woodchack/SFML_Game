#include <iostream>


#include "Game.h"

int main()
{
	// Init Game engine
	std::srand(static_cast<unsigned int> (time(NULL)));
	
	Game game;
	

	while (game.windowIsRunning()) // Game loop
	{
		
		// Update
		game.update();
		//Render
		game.render();
		

		//Drawing
		
		
	}


	return 0;
}