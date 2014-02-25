#ifndef LOGO_STATE_H
#define LOGO_STATE_H

#include "Game.h"
#include "GameState.h"
#include "BlackScreen.h"
#include "Timer.h"
#include "SDL/SDL.h"
#include "Sprite.h"

class LogoState: public GameState
{
	public:
		void Init();
		void Clean();
		void Pause();
		void Resume();
		
		void HandleEvents(Game* game);
		void Update (Game* game);
		void Draw(Game* game);
		
		static LogoState* Instance()
		{
			return &m_LogoState;
		}
	protected:
		LogoState() {}
	private:
		static LogoState m_LogoState;
		SDL_Surface* logo;
		BlackScreen blackScreen;
		bool finished;
		Timer timer;
		Timer waitTimer;
		
};
#endif
