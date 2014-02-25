#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "SDL/SDL.h"
#include "Sprite.h"
#include "IDrawable.h"
#include "DrawableObject.h"
#include "IUpdateable.h"
#include "GamePlayObject.h"

class Background : public GamePlayObject
{
	public:
		float DistanceScrolled();		
		void Update(Uint32 deltaTicks);
		void Draw(SDL_Surface* surface);
		void Init();		
		void Clean();
	private:
		float distanceScrolled;		
		
};

#endif
