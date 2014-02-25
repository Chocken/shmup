#ifndef DRAWABLE_OBJECT_H
#define DRAWABLE_OBJECT_H

#include "SDL/SDL.h"
#include "Sprite.h"
#include "Vector2D.h"
#include "IDrawable.h"

class DrawableObject
{

	public:	
		void SetIsActive(bool activity);
		bool GetIsActive();
		virtual void Draw(SDL_Surface* surface) = 0;
		Vector2D Center();
		SDL_Surface* sprite;
		float width, height;		
		float x, y;	
		int isActive; 
		
		
};

#endif
