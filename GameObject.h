#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Game.h" 
#include "Sprite.h"
#include "Vector2D.h"

class GameObject
{
	public:

		Vector2D position;
	
		GameObject() {}
		~GameObject() {}
		
		void Load(char* filename);
		void Update();
		void Draw(SDL_Surface* surface);
		void Clean();
		
	private:
		
		SDL_Surface* m_pSprite;
		
};

#endif


