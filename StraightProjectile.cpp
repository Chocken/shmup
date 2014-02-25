#include "StraightProjectile.h"
#include <iostream>

StraightProjectile::StraightProjectile(Vector2D FiringPoint, Vector2D target, int speed, int weaponDamage)
{
	direction = target;
	velocity = speed;
	x = FiringPoint.x;
	y = FiringPoint.y;	
	damage = weaponDamage;
	destroyOnCollision = true;	
}

void StraightProjectile::Update(Uint32 deltaTicks)
{
	x += direction.x * velocity * ( deltaTicks / 1000.f );
	y += direction.y * velocity * ( deltaTicks / 1000.f );	

	if((y + height) < - 5)
	{
		isActive = false;		
	}
}

void StraightProjectile::Draw(SDL_Surface* surface)
{	
	if (Sprite::Draw(surface, sprite, x, y) == false)
	{
		printf("straight projectile not drawn successfully\n");
	}

}

void StraightProjectile::OnCollision(Enemy *enemy)
{
	enemy->TakeDamage(damage);
	if(destroyOnCollision)
	{	
		isActive = false;
	}
}
