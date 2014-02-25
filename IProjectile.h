#ifndef IPROJECTILE_H
#define IPROJECTILE_H

class IProjectile: public DrawableObject
{
	public:
		protected void StraightProjectile(Vector2D target, int speed) = 0;
		void Update(Uint32 deltaTicks);		
	protected:
		Vector2D direction;
		int velocity;
};

#endif
