#ifndef  BLACK_SCREEN_H
#define  BLACK_SCREEN_H

#include "SDL/SDL.h"
#include "DrawableObject.h"
#include "IUpdateable.h"

enum Phase
{
	FADINGIN,	
	FADINGOUT,
	NOFADE
};

class BlackScreen : public DrawableObject
{
	public:
		BlackScreen();
		BlackScreen(int fadeRate);		
		void Draw(SDL_Surface* surface);
		void Update(Uint32 deltaTicks);
		bool FullAlpha();
		void Clear();
		void SetToFadeOut();
		void SetToFadeIn();
		void SetBlack();
		

	private:
		Phase phase;
		bool fadeIn;
		bool fading;
		int alpha;
		int _fadeRate;
};

#endif
