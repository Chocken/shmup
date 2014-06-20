#include <iostream>
#include "PlayState.h"
#include "Game.h"
#include "Timer.h"
#include "Level.h"
#include "LevelFactory.h"
#include "MenuState.h"
#include "ContinueState.h"
#include <iostream>

PlayState PlayState::m_PlayState;
TextRenderer PlayState::textRenderer;

PlayState::PlayState() : levelFinished(false), bossDestroyed(false)
{
}

void PlayState::Init()
{
	levelFinished = false;	
	level.Init(2);
	blackScreen = BlackScreen(1000);
	blackScreen.sprite = Sprite::Load(const_cast<char *>("blackScreen.png"), false);
	SDL_Color textColor = { 255, 255, 255 };
	textRenderer = TextRenderer(const_cast<char *>("manaspc.ttf"),28, textColor);
}

void PlayState::Clean()
{
	level.Clean();
	blackScreen.Clear();
}

void PlayState::Pause()
{
	level.Pause();
}

void PlayState::Resume()
{
	
}

void PlayState::HandleEvents(Game* game)
{
	SDL_Event event;				
	while (SDL_PollEvent(&event)) 
	{
		level.HandleEvents(event, game);		
		switch (event.type) 
		{
			case SDL_QUIT:										
				game->Quit();				
				break;
			case SDL_KEYDOWN:
			switch(event.key.keysym.sym)
			{
				case SDLK_RETURN:
					levelFinished = true;															
					break;
			}
		}
	}
	
}

void PlayState::Update(Game* game) 
{	
	level.Update();	

	if(bossDestroyed == true)
	{
		endTimer.start();
		bossDestroyed = false;		
	}

	if(playerDestroyed == true)
	{
		endTimer.start();
		playerDestroyed = false;		
	}

	if(endTimer.get_ticks() > 5000) 
	{		
		levelFinished = true;
		endTimer.reset();	
	}
	if(levelFinished == true)
	{		
		blackScreen.Update(fadeTimer.get_ticks());
		if(blackScreen.FullAlpha())
		{						
			game->ChangeState(ContinueState::Instance());			
		}		
	}
	fadeTimer.start();
}

void PlayState::Draw(Game* game) 
{
	level.Draw(game);
	blackScreen.Draw(game->GetScreen());
	SDL_Flip(game->GetScreen());
}


