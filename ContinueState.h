#ifndef  _CONTINUE_STATE_H_
#define _CONTINUE_STATE_H_

#include "Game.h"
#include "GameState.h"
#include "Timer.h"
#include "BlackScreen.h"
#include "TextRenderer.h"

#include <list>

class ContinueState : public GameState
{
	public:
		void Init();
		void Clean();
		
		void Pause();
		void Resume();
		
		void HandleEvents(Game* game);
		void Update(Game* game);
		void Draw(Game* game);

		static ContinueState* Instance()
		{
			return &m_ContinueState;
		}

		protected:
		
		ContinueState();
	private:
		int secondsLeft;
		TextRenderer continueMessage;
		TextRenderer countdown;
		Timer countdownTimer;
		static ContinueState m_ContinueState;		
		BlackScreen blackScreen;	
};
#endif
