#include <stdio.h>

#include "SDL/SDL.h"
#include "Game.h"
#include "PauseState.h"

PauseState PauseState::m_PauseState;

void PauseState::Init()
{	
	pauseSprite = NULL;
	printf("about to load pauseSprite\n");
	//pauseSprite = Sprite::Load(const_cast<char *>("test.bmp"), false);		      
	
	printf("PauseState Init Successful\n");
}

void PauseState::Clean()
{
	printf("PauseState Clean Successful\n");
}

void PauseState::Resume(){}

void PauseState::Pause() {}

void PauseState::HandleEvents(Game* game)
{
	SDL_Event event;
	
	while (SDL_PollEvent(&event)) {
		switch (event.type) 
		{
			case SDL_QUIT:
				game->Quit();
				break;
				
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_SPACE:
					game->PopState();
					break;
				}
		}
	}
}

void PauseState::Update(Game* game) 
{
}

void PauseState::Draw(Game* game) 
{
	//Sprite::Draw(game->GetScreen(), pauseSprite, 0, 0);
	SDL_Flip(game->GetScreen());
}


