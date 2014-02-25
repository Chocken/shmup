#ifndef  BLACK_SCREEN_H
#define  BLACK_SCREEN_H

#include "SDL/SDL.h"
#include "DrawableObject.h"
#include "IUpdateable.h"

class BlackScreen : public DrawableObject
{
	public:
		BlackScreen();
		BlackScreen(int fadeRate);
		BlackScreen(int fadeRate, bool FadeIn);
		~BlackScreen();
		void Draw(SDL_Surface* surface);
		void Update(Uint32 deltaTicks);
		bool FullAlpha();
		void Clear();
		void SetToFadeOut();
		

	private:
		bool fadeIn;
		bool fading;
		int alpha;
		int _fadeRate;
};

#endif
