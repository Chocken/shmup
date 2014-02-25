#ifndef I_ENEMY_H
#define I_ENEMY_H

#include "Vector2D.h"
#include "SDL/SDL.h"

class IEnemy
{
	virtual Vector2D CollisionCenter() = 0;
	virtual void Draw(SDL_Surface* surface) = 0;
	virtual void SetIsActive(bool activity) = 0;
	virtual	bool GetIsActive() = 0;
	virtual void Update(Uint32 deltaTicks) = 0;
	virtual void TakeDamage(int damage) = 0;
};

#endif
