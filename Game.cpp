#include "Game.h"
#include "GameState.h"
#include "SDL/SDL_mixer.h"
#include "GameObjects.h"
#include <stdio.h>
#include <iostream>


Game::Game()
{
	
}

void Game::Init(const char* title, int width, int height,
	                int bpp, bool fullscreen)
{
	int flags = 0;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_WM_SetCaption(title,title);

	keystate = SDL_GetKeyState(NULL);
	
	if(fullscreen)
	{
		flags = SDL_FULLSCREEN;
	}
	
	screen = SDL_SetVideoMode(width, height, bpp, flags);
	
	m_pScreen = SDL_SetVideoMode(width, height, bpp, flags);
	
	m_bFullscreen = fullscreen;
    
    	stick = SDL_JoystickOpen( 0 );
    	
    	if( stick == NULL )
    	{
		printf("problem opening joystick");
		Quit();        	
    	}
	
	m_bRunning = true;

	if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 1024 ) == -1 ) 
	{ 
		Quit(); 
	}
	
	if( TTF_Init() == -1 ) { printf("failed to initialize ttf\n");}
	
	printf("Game Initialised Successfully\n");
	timer.start();
}

void Game::ChangeState(GameState* state)
{
	
	if(!states.empty())
	{		
		states.back()->Clean();
		states.pop_back();		
	}
	
	states.push_back(state);
	states.back()->Init();
}

void Game::PushState(GameState* state)
{
	if(!states.empty())
	{
		states.back()->Pause();
	}
	states.push_back(state);
	states.back()->Init();
}

void Game::PopState()
{
	if(!states.empty())
	{
		states.back()->Clean();
		states.pop_back();
	}
	if(!states.empty())
	{
		states.back()->Resume();
	}
}

void Game::HandleEvents()
{
	states.back()->HandleEvents(this);
}

void Game::Update()
{
	timer.start();
	states.back()->Update(this);	
	
	/*if( timer.get_ticks() < 1000 / FRAMES_PER_SECOND) 
	{		
		SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - timer.get_ticks());								
	}*/
	

}

void Game::Draw()
{

	states.back()->Draw(this);

}

void Game::Cleanup()
{
	while(!states.empty())
	{
		states.back()->Clean();
		states.pop_back();
	}
	SDL_Quit();
}

void Game::Quit()
{
	m_bRunning = false;
}

bool Game::Running()
{
	return m_bRunning;
}

SDL_Surface* Game::GetScreen() 
{
	return m_pScreen;
}	


 
