#ifndef  _PLAY_STATE_H_
#define _PLAY_STATE_H_

#include "Game.h"
#include "GameState.h"
#include "Timer.h"
#include "Level.h"
#include "LevelFactory.h"
#include "BlackScreen.h"
#include "TextRenderer.h"

#include <list>

enum StatePhase
{
	PLAY,
	ENDING,
	DONE
};

class PlayState : public GameState
{
	public:
		void Init();
		void Clean();
		
		void Pause();
		void Resume();
		
		void HandleEvents(Game* game);
		void Update(Game* game);
		void Draw(Game* game);

		static TextRenderer textRenderer;
	
		static PlayState* Instance()
		{
			return &m_PlayState;
		}

		
		bool bossDestroyed;
		bool playerDestroyed;
		
	protected:
		
		PlayState();
		
	private:
		StatePhase statePhase;		
		static PlayState m_PlayState;
		Level level; 
		Timer fadeTimer;
		Timer endTimer;
		BlackScreen blackScreen;		
		
};

#endif


