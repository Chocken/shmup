#ifndef WEAPON_ENEMY_H
#define WEAPON_ENEMY_H

#include "BasicEnemy.h"
#include "StraightWeapon.h"
#include "IUpdateable.h"
class WeaponEnemy : public BasicEnemy
{
	public:
		void Update(Uint32 deltaTicks);
};

#endif
