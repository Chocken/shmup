#ifndef INTRO_STATE_H
#define INTRO_STATE_H

#include "Game.h"
#include "GameState.h"
#include "Timer.h"
#include "SDL/SDL.h"
#include "Sprite.h"
#include "SDL/SDL_ttf.h"
#include "TextRenderer.h"
#include "MenuState.h"
#include <string>
#include <vector>

using namespace std;

class IntroState: public GameState
{
	public:
		void Init();
		void Clean();
		void Pause();
		void Resume();
		
		void HandleEvents(Game* game);
		void Update (Game* game);
		void Draw(Game* game);
		
		static IntroState* Instance()
		{
			return &m_IntroState;
		}

	protected:
		IntroState() {}
	private:
		Timer timer;
		std::vector<string> _intro;	
		TextRenderer _textRenderer;
		static IntroState m_IntroState;
		SDL_Surface* _introSprite;
		float textY;		
		SDL_Event event;
		
};
#endif
