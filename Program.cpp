#include "Game.h"
#include "MenuState.h"
#include "LogoState.h"
#include "Settings.h"
#include "Timer.h"

int main(int argc, char*argv[])
{
	Game game;
	game.Init("Space Shooter",Settings::ScreenWidth,Settings::ScreenHeight,32,false);
	game.ChangeState(LogoState::Instance());	
	
	while(game.Running())
	{
		game.HandleEvents();	
		game.Update();		
		game.Draw();	
	}
	
	printf("about to call cleanup\n");
	game.Cleanup();
	
	return 0;
}
