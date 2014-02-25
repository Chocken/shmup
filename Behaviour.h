#ifndef MOVE_MENT_H
#define MOVE_MENT_H

#include "Vector2D.h"
#include "SDL/SDL.h"

class Behaviour
{
	public:
		virtual void Update(Uint32 deltaTicks) = 0;
};
#endif
