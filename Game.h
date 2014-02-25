#ifndef _GAME_H_
#define _GAME_H_

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "Sprite.h"
#include "Timer.h"
#include <vector>

class GameState;

class Game
{
	public:

		static Uint8 *keystate;
		Game();
		void Init(const char* title, int width, int height, int bpp, bool fullscreen);
		SDL_Surface* screen;		
		
		void ChangeState(GameState* state);
		void PushState(GameState* state);
		void PopState();
		
		void HandleEvents();
		void Update();
		void Draw();
		void Cleanup();
		void Quit();
		SDL_Surface* GetScreen();
		bool Running();
		
	private:
		std::vector<GameState*> states;
		bool m_bRunning;
		bool m_bFullscreen;	
		SDL_Surface* m_pScreen;
		SDL_Joystick* stick;
		Timer timer;
		static const int FRAMES_PER_SECOND = 60; 
};

#endif
