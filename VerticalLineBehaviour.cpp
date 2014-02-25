#include "VerticalLineBehaviour.h"
#include "GameObjects.h"

VerticalLineBehaviour::VerticalLineBehaviour(float Speed,BasicEnemy* basicEnemy)
{
	speed = Speed;
	enemy = basicEnemy;
	fired = false;
}


void VerticalLineBehaviour::Update(Uint32 deltaTicks)
{
	enemy->y += speed * (deltaTicks/1000.f);

	/*if(enemy->y > 200 && fired == false)
	{
		Vector2D direction = (GameObjects::Instance()->playerShip.Center() - enemy->Center());			
		enemy->weapons[0]->Fire(enemy->Center(),Vector2D::Normalize(direction));
		fired = true;
	}*/	
}
