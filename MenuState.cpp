#include "SDL/SDL.h"
#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"
#include "IntroState.h"
#include "GameObjects.h"
#include <string>

MenuState MenuState::m_MenuState;

void MenuState::Init()
{
	menuSprite = NULL;	
	menuSprite = Sprite::Load(const_cast<char *>("blackScreen.png"), false);
	printf("MenuState Init Successful\n");	
	SDL_Color textColor = { 255, 255, 255 };
	textRenderer = TextRenderer(const_cast<char *>("manaspc.ttf"),28, textColor);
	timer.start();
	GameObjects::Instance()->PlayerLives = 2;
	GameObjects::Instance()->PlayerScore = 0;
}

void MenuState::Clean()
{
	printf("MenuState Clean Successful\n");
}

void MenuState::Pause()
{
	printf("MenuState Paused\n");
}

void MenuState::Resume()
{
	printf("MenuState Resumed\n");
}

void MenuState::HandleEvents(Game* game)
{

	while (SDL_PollEvent(&event)) 
	{		
		switch (event.type) 
		{
			case SDL_QUIT:
				game->Quit();
				break;

			case SDL_KEYDOWN:				 
				 switch(event.key.keysym.sym)
				{

				 case SDLK_SPACE:			
					  game->ChangeState(PlayState::Instance());						
					  break;
			 	}
		}
	}
}

void MenuState::Update(Game* game)
{	
	if(timer.get_ticks() > 5000)
	{
		game->ChangeState(IntroState::Instance());
	}

}

void MenuState::Draw(Game* game)
{	
	Sprite::Draw(game->GetScreen(), menuSprite, 0, 0);

	textRenderer.SetText("CHANTICLEER HEGEMONY 2");
	textRenderer.Draw(game->GetScreen(),75, 300);

	textRenderer.SetText("Press space game to initation");
	textRenderer.Draw(game->GetScreen(),30, 400);
	
	SDL_Flip(game->GetScreen());
}

