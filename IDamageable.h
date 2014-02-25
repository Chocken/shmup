#ifndef I_DAMAGEABLE_H
#define I_DAMAGEABLE_H

class IDamageable
{
	public:		
		virtual void TakeDamage(int damage) = 0;
};

#endif
