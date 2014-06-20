#include <iostream>
#include <string>
#include "ContinueState.h"
#include "MenuState.h"

ContinueState ContinueState::m_ContinueState;

ContinueState::ContinueState() : secondsLeft(10)
{
}

void ContinueState::Init()
{	
	blackScreen = BlackScreen(1000, true);
	blackScreen.sprite = Sprite::Load(const_cast<char *>("blackScreen.png"), false);
	SDL_Color textColor = { 255, 255, 255 };
	continueMessage = TextRenderer(const_cast<char *>("manaspc.ttf"),28, textColor);
	continueMessage.SetText("Continue?");
	countdown = TextRenderer(const_cast<char *>("manaspc.ttf"),28, textColor);
	countdown.SetText("10");
	countdownTimer.start();
}

void ContinueState::Clean()
{
	
}

void ContinueState::Pause()
{
	
}

void ContinueState::Resume()
{
	
}

void ContinueState::HandleEvents(Game* game)
{
	SDL_Event event;				
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
				case SDLK_RETURN:																				
					break;
			}
		}
	}	
}

void ContinueState::Update(Game* game) 
{	
	if(countdownTimer.get_ticks() > 2000)
	{
		countdown.Free();		
		countdown.SetText(std::to_string(--secondsLeft));
		countdownTimer.start();
	}

	if(secondsLeft == 0)
	{
		game->ChangeState(MenuState::Instance());
	}
}

void ContinueState::Draw(Game* game) 
{	
	blackScreen.Draw(game->GetScreen());
	continueMessage.Draw(game->GetScreen(),250,300);
	countdown.Draw(game->GetScreen(),250,350);
	SDL_Flip(game->GetScreen());
}
