#ifndef VERTICAL_LINE_BEHAVIOUR_H
#define VERTICAL_LINE_BEHAVIOUR_H

#include "SDL/SDL.h"
#include "Vector2D.h"
#include "Behaviour.h"
#include "IWeapon.h"
#include"BasicEnemy.h"

class VerticalLineBehaviour: public Behaviour
{
	public:
		VerticalLineBehaviour(float Speed, BasicEnemy* basicEnemy);
		void Update(Uint32 deltaTicks);
	private:
		float speed;		
		bool fired;
		BasicEnemy* enemy;		
};
#endif
