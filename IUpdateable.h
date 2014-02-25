#ifndef  IUPDATEABLE_H
#define  IUPDATEABLE_H

#include "SDL/SDL.h"

class IUpdateable
{
	public:
		virtual void Update(Uint32 deltaTicks) = 0;				
};

#endif
