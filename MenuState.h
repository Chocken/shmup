#ifndef _MENU_STATE_H_
#define _MENU_STATE_H_

#include "SDL/SDL.h"
#include "GameState.h"
#include "Sprite.h"
#include "SDL/SDL_ttf.h"
#include "TextRenderer.h"

class MenuState : public GameState
{
	public:
		void Init();
		void Clean();
		void Pause();
		void Resume();
		
		void HandleEvents(Game* game);
		void Update (Game* game);
		void Draw(Game* game);
		
		static MenuState* Instance()
		{
			return &m_MenuState;
		}
	
	protected:
		MenuState() {}
	
	private:
		static MenuState m_MenuState;
		SDL_Surface* menuSprite;	
		TextRenderer textRenderer;
		Timer timer;
		SDL_Event event;
			
};

#endif
