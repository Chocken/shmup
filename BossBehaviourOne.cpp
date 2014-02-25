#include "BossBehaviourOne.h"
#include "GameObjects.h"
#include "MathsHelper.h"
#include <iostream>


BossBehaviourOne::BossBehaviourOne(BasicEnemy* basicEnemy, Vector2D P0, Vector2D P1, Vector2D P2, Vector2D P3, float Speed)
{
	p0 = P0;
	p1 = P1;
	p2 = P2;
	p3 = P3;
	speed = Speed;
	enemy = basicEnemy;
}

BossBehaviourOne::BossBehaviourOne(BasicEnemy* basicEnemy)
{
	p0 = Vector2D(0,-800);
	p1 = Vector2D(0,20);
	p2 = Vector2D(355,20);
	p3 = Vector2D(355,-800);
	speed = 0.2;
	enemy = basicEnemy;
	movementStage = ENTERING;
	currentWeapon = SPIN;

	forwards = true;
	secondaryWeaponFired = false;

	enemy->x = 175;
	enemy->y = -200;
	t = 0.5;
	target = Vector2D(1, 0);
	shootCount = 0;
}

void BossBehaviourOne::Update(Uint32 deltaTicks)
{
	if(movementStage == ENTERING)
	{
		enemy->y += 100 * (deltaTicks/1000.f);
		if(enemy->y > 120)
		{			
			movementStage = MOVING;
			shootTimer.start();
		}
	}

	else if(movementStage == MOVING)
	{
		
		if(forwards)
		{
			t += speed * (deltaTicks/1000.f);
		}
		else
		{
			t -= speed * (deltaTicks/1000.f);
		}

		if(t >= 1) {t = 1; forwards = !forwards;}
		if(t <= 0) {t = 0; forwards = !forwards;}	

		Vector2D location = MathsHelper::CatmullRom(p0,p1,p2,p3,t);

		enemy->x = location.x;
		enemy->y = location.y;

		if(currentWeapon == SPIN)
		{		
			if(shootTimer.get_ticks() > 50)
			{
				target = MathsHelper::Rotate(target,0.3);
				enemy->weapons[0]->Fire(enemy->Center(),target);
				shootTimer.start();
				shootCount++;
			}
			if(shootCount > 30)
			{
				shootCount = 0;
				currentWeapon = TARGET;
				shootTimer.start();								
			}
		}
		else if(currentWeapon == TARGET)
		{
			if(shootTimer.get_ticks() > 1000 && !secondaryWeaponFired)
			{
				Vector2D direction = (GameObjects::Instance()->playerShip.Center() - enemy->Center());	
				enemy->weapons[1]->Fire(enemy->Center(),Vector2D::Normalize(direction));
				secondaryWeaponFired = true;				
				waitTimer.start();
			}

			if(waitTimer.get_ticks() > 1000)
			{
				target = Vector2D(1, 0);
				currentWeapon = SPIN;
				secondaryWeaponFired = false;
				waitTimer.reset();
			}
		}
	}
}
