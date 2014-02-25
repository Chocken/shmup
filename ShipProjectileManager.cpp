#include "ShipProjectileManager.h"
#include "StraightProjectile.h"
#include "Vector2D.h"
#include "GameObjectFactory.h"
void ShipProjectileManager::AddProjectile(GamePlayObject* object)
{
	printf("about to add projectile\n");	
	gamePlayObjects.push_back(object);
	printf("projectile added\n");
}

void ShipProjectileManager::Update(Uint32 deltaTicks)
{
	boost::ptr_list<GamePlayObject>::iterator gamePlayObjectIter = gamePlayObjects.begin();
	while (gamePlayObjectIter != gamePlayObjects.end())
	{	
		
		if(gamePlayObjectIter->GetIsActive() == false)
		{			
			gamePlayObjectIter = gamePlayObjects.erase(gamePlayObjectIter);
		}
		else
		{
			gamePlayObjectIter->Update(deltaTicks);
			++gamePlayObjectIter;
		}
	}
}

void ShipProjectileManager::Draw(Game* game)
{
	boost::ptr_list<GamePlayObject>::iterator gamePlayObjectIter = gamePlayObjects.begin();
	while (gamePlayObjectIter != gamePlayObjects.end())
	{		
		
			gamePlayObjectIter->Draw(game->GetScreen());			
			++gamePlayObjectIter;		
	}
}
