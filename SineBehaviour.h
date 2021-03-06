#ifndef SINE_MOVEMENT_H
#define SINE_MOVEMENT_H

#include "Behaviour.h"
#include "BasicEnemy.h"

class SineBehaviour: public Behaviour
{
	public:
		SineBehaviour(BasicEnemy* basicEnemy,float Amplitude, float Frequency, float Speed);
		void Update(Uint32 deltaTicks);
		float radius;
		float numTicks;
		float amplitude;
		float frequency;
		float speed;
		BasicEnemy *enemy;		
};
#endif
