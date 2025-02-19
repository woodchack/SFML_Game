#include <iostream>


#include "Game.h"

int main()
{
	// Init Game engine
	
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