#include <iostream>
#include "PlayState.h"
#include "Game.h"
#include "Timer.h"
#include "Level.h"
#include "LevelFactory.h"
#include "MenuState.h"

PlayState PlayState::m_PlayState;
TextRenderer PlayState::textRenderer;

void PlayState::Init()
{
	printf("playstate init\n");
	//level = Level();		
	level.Init(1);
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
		}
	}
	
}

void PlayState::Update(Game* game) 
{	
	level.Update();	
	if(level.levelFinished == true)
	{				
		blackScreen.Update(timer.get_ticks());
		if(blackScreen.FullAlpha())
		{			
			game->ChangeState(MenuState::Instance());
		}		
	}
	timer.start();
}

void PlayState::Draw(Game* game) 
{
	level.Draw(game);
	blackScreen.Draw(game->GetScreen());
	SDL_Flip(game->GetScreen());
}

