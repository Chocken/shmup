#include "SplineBehaviour.h"
#include "MathsHelper.h"
#include <iostream>

SplineBehaviour::SplineBehaviour(BasicEnemy* basicEnemy, Vector2D P0, Vector2D P1, Vector2D P2, Vector2D P3, float Speed)
{
	p0 = P0;
	p1 = P1;
	p2 = P2;
	p3 = P3;
	speed = Speed;
	enemy = basicEnemy;
}

SplineBehaviour::SplineBehaviour(BasicEnemy* basicEnemy)
{
	p0 = Vector2D(100,100);
	p1 = Vector2D(200,200);
	p2 = Vector2D(400,200);
	p3 = Vector2D(600,100);
	speed = 50;
	enemy = basicEnemy;
}

void SplineBehaviour::Update(Uint32 deltaTicks)
{
	if(forwards)
	{
		t += speed * (deltaTicks/1000.f);
	}
	else
	{
		t -= speed * (deltaTicks/1000.f);
	}

	if(t > 1) {t = 1; forwards = !forwards;}
	if(t < 0) {t = 0; forwards = !forwards;}

	Vector2D location = MathsHelper::CatmullRom(p0,p1,p2,p3,t);
	
	enemy->x = location.x;
	enemy->y = location.y;
}
