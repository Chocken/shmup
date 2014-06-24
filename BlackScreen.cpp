#include "BlackScreen.h"
#include <iostream>

BlackScreen::BlackScreen(){}

BlackScreen::BlackScreen(int fadeRate)
{
	x = 0;
	y = 0; 
	alpha = 0;
	phase = NOFADE;
	_fadeRate = fadeRate;
}


void BlackScreen::Draw(SDL_Surface* surface)
{	
	if (Sprite::Draw(surface, sprite, x,y, alpha) == false) printf("blackscreen draw failed\n");
}

void BlackScreen::Update(Uint32 deltaTicks)
{
	if(phase == FADINGIN)
	{			
		if (alpha > 0)
		{					
			alpha -= _fadeRate * (deltaTicks/1000.f);

			if (alpha <= 0)
			{
				alpha = 0;
				phase = NOFADE;
			}
		}
	}

	else if(phase == FADINGOUT)
	{
		if(alpha <= 254)
		{			
			alpha += _fadeRate * (deltaTicks/1000.f);
			
			if (alpha >= 254) {phase = NOFADE;}		
		}
	}		
}

void BlackScreen::SetToFadeOut()
{	
	phase = FADINGOUT;	
}

void BlackScreen::SetToFadeIn()
{		
	phase = FADINGIN;
	alpha = 255;
}

void BlackScreen::Clear()
{
	alpha = 0;
	phase = NOFADE;
}

void BlackScreen::SetBlack()
{
	phase = NOFADE;
	alpha = 255;
}

bool BlackScreen::FullAlpha()
{
	return alpha >= 254;
}

