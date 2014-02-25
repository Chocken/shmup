#ifndef SPLINE_BEHAVIOUR_H
#define SPLINE_BEHAVIOUR_H

#include "Behaviour.h"
#include "BasicEnemy.h"
#include "SDL/SDL.h"

class SplineBehaviour : public Behaviour
{
	public:
		SplineBehaviour(BasicEnemy* basicEnemy,Vector2D P0, Vector2D P1, Vector2D P2, Vector2D P3, float Speed);
		SplineBehaviour(BasicEnemy* basicEnemy);
		void Update(Uint32 deltaTicks);

	private:
		BasicEnemy* enemy;
		Vector2D p0,p1,p2,p3;
		float t, speed;
		bool forwards;
};

#endif
