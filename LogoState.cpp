#include "LogoState.h"
#include "MenuState.h"

LogoState LogoState::m_LogoState;

void LogoState::Init()
{
	blackScreen = BlackScreen(300);
	blackScreen.SetToFadeIn();
	blackScreen.sprite = Sprite::Load(const_cast<char *>("blackScreen.png"), false);
	logo = Sprite::Load(const_cast<char *>("pretendlogo.png"), false);
	waitTimer.start();
	finished = false;
}

void LogoState::Clean()
{
	timer.stop();
	blackScreen.Clear();
}

void LogoState::Pause()
{
}

void LogoState::Resume()
{
}

void LogoState::HandleEvents(Game* game)
{
	SDL_Event event;				
	while (SDL_PollEvent(&event)) 
	{		
		switch (event.type) 
		{
			case SDL_KEYDOWN:				 
				switch(event.key.keysym.sym)
				{
					case SDLK_SPACE:
						printf("space pressed\n");
						blackScreen.SetToFadeOut();
						finished = true;
				}
				break;				
			case SDL_QUIT:							
				game->Quit();
				break;
		}
	}	
}

void LogoState::Update(Game* game) 
{
	
	blackScreen.Update(timer.get_ticks());
	if (!finished && waitTimer.get_ticks() > 3000)
	{		
		blackScreen.SetToFadeOut();
		finished = true;
	}	
	if(finished)
	{			
		if(blackScreen.FullAlpha())
		{			
			game->ChangeState(MenuState::Instance());
		}		
	}
	timer.start();
}

void LogoState::Draw(Game* game)
{
	if (Sprite::Draw(game->GetScreen(), logo, 0,0) == false) printf("logo draw failed\n");
	blackScreen.Draw(game->GetScreen());
	SDL_Flip(game->GetScreen());
}
