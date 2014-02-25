#ifndef BOSS_BEHAVIOUR_ONE_H
#define BOSS_BEHAVIOUR_ONE_H

#include "SDL/SDL.h"
#include "Vector2D.h"
#include "Behaviour.h"
#include "IWeapon.h"
#include"BasicEnemy.h"
#include "Timer.h"

enum MovementStage
{
	ENTERING,
	MOVING,
};

enum CurrentWeapon
{
	SPIN,
	TARGET
};

class BossBehaviourOne: public Behaviour
{
	public:
		BossBehaviourOne(BasicEnemy* basicEnemy, Vector2D P0, Vector2D P1, Vector2D P2, Vector2D P3, float Speed);
		BossBehaviourOne(BasicEnemy* basicEnemy);
		void Update(Uint32 deltaTicks);
	private:	
		BasicEnemy* enemy;
		Vector2D p0,p1,p2,p3;
		float t, speed;
		bool forwards;
		bool secondaryWeaponFired;
		MovementStage movementStage;
		Timer shootTimer;
		Timer waitTimer;
		Vector2D target;
		CurrentWeapon currentWeapon;
		int shootCount;	
};
#endif
