#ifndef LAZER_PROJECTILE_H
#define LAZER_PROJECTILE_H

#include "StraightProjectile.h"

class LazerProjectile : public StraightProjectile
{
	public:
		void OnCollision(Enemy *enemy);
	
};

#endif
