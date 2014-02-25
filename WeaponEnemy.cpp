#include "WeaponEnemy.h"
#include "GameObjects.h"

void WeaponEnemy::Update(Uint32 deltaTicks)
{
	BasicEnemy::Update(deltaTicks);

	
	if(y > 200 && fired == false)
	{
		std::cout << x << " - " << y << std::endl;
		Vector2D playerShipLocation = Vector2D(GameObjects::Instance()->playerShip->Center());			
		Vector2D Direction = Vector2D::Normalize(playerShipLocation - Center());
		straightWeapon.Fire(Center(), Direction, 200,10);
		fired = true;
	}	

}
