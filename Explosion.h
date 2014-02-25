#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "DrawableObject.h"
#include "Timer.h"
#include "SDL/SDL.h"
#include "Vector2D.h"
#include "IUpdateable.h"
#include "GamePlayObject.h"

class Explosion : public DrawableObject, public IUpdateable
{
	public:
		Explosion();		
		Explosion(Vector2D CenterLocation, int Width, int Height);
		Explosion(const Explosion &explosion);		
		void Draw(SDL_Surface* surface);
		void Update(Uint32 deltaTicks);
		Vector2D drawCenter;		
		Vector2D sheetVector;
		bool finished;
		int frames;

	private:
		Vector2D drawVector;
		Timer timer;		
		Vector2D sheet;		
};

#endif
