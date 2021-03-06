#include "IntroState.h"
#include <fstream>
#include <iostream>
using namespace std;

IntroState IntroState::m_IntroState;

void IntroState::Init()
{	
	_introSprite = Sprite::Load(const_cast<char *>("blackScreen.png"), false);
	SDL_Color textColor = { 255, 255, 255 };
	_textRenderer = TextRenderer(const_cast<char *>("manaspc.ttf"),28, textColor);

	ifstream myfile("Intro.txt");
	
	textY = 810;
	string line;
	printf("intro init\n");

	if (myfile.is_open())
  	{
  		while ( getline (myfile,line) )
  		{
	 		_intro.push_back(line);
			
   		}
   		myfile.close();
  	}
	timer.start();
}

void IntroState::Clean()
{	
	timer.stop();
	_intro.clear();
	SDL_FreeSurface(_introSprite);
}

void IntroState::Pause()
{
	printf("MenuState Paused\n");
}

void IntroState::Resume()
{
	printf("MenuState Resumed\n");
}

void IntroState::HandleEvents(Game* game)
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
					printf("space pressed\n");
					game->ChangeState(MenuState::Instance());						
					break;
			 	}
		}
	}
}

void IntroState::Update(Game* game)
{
	
	textY -= 50 * (timer.get_ticks() / 1000.f);
	if (textY + (_intro.size() * 30) < 0)
	{
		game->ChangeState(MenuState::Instance());
	}

	timer.start();	
}

void IntroState::Draw(Game* game)
{
	if(Sprite::Draw(game->GetScreen(), _introSprite, 0, 0) == false)
	{
		printf("introbackground draw failed\n");
	}

	vector<string>::iterator iter = _intro.begin();

	int offset = 0;

	while(iter != _intro.end())
	{
		_textRenderer.SetText(*iter);
		_textRenderer.Draw(game->GetScreen(), 20, textY + offset);
		_textRenderer.Free();
		offset += 30;
		++iter;
	}
	
	
	SDL_Flip(game->GetScreen());
}

