#ifndef GAME_OBJECT_SPEC_H
#define GAME_OBJECT_SPEC_H

#include "SDL/SDL.h"
#include "Sprite.h"
#include "Vector2D.h"
#include "CollisionType.h"
#include <string>

class GameObjectSpec
{
	public:		
		CollisionType collisionType;
		float width, height, collisionWidth, collisionHeight;
		Vector2D collisionOffset;
};

#endif
