#ifndef ENEMY_SPEC_H
#define ENEMY_SPEC_H
#include "GameObjectSpec.h"
#include "Behaviour.h"
#include "Vector2D.h"
#include <string>
using namespace std;

class EnemySpec
{
	public:
		string sprite;
		string explosionSound;
		string explosionSprite;
		string collisionType;		
		float width, height, collisionWidth, collisionHeight, amplitude, frequency, speed;
		Vector2D collisionOffset;		
		Vector2D startingLocation;
		int explFactoryWidth, explFactoryHeight, explFactoryFrames;		
		int life;
		vector<string> weapons;
		string behaviour;
		Vector2D p0,p1,p2,p3;		
		bool boss;
};

#endif
