#include "BlackScreen.h"
#include <iostream>

BlackScreen::BlackScreen(){}

BlackScreen::BlackScreen(int fadeRate)
{
	x = 0;
	y = 0; 
	alpha = 0;
	fading = true;
	fadeIn = false;
	_fadeRate = fadeRate;
}

BlackScreen::BlackScreen(int fadeRate,bool FadeIn)
{
	x = 0;
	y = 0;
	_fadeRate = fadeRate; 
	fadeIn = FadeIn;
	fading = true;
	if(FadeIn)
	{
		alpha = 255;
	}
	else alpha = 0;
}

BlackScreen::~BlackScreen()
{
	alpha = 0;
}

void BlackScreen::Draw(SDL_Surface* surface)
{	
	if (Sprite::Draw(surface, sprite, x,y, alpha) == false) printf("blackscreen draw failed\n");
}

void BlackScreen::Update(Uint32 deltaTicks)
{
	if(fading)
	{
		if (fadeIn && alpha > 0)
		{			
			alpha -= _fadeRate * (deltaTicks/1000.f);

			if (alpha <= 0)
			{
				alpha = 0;
				fading = false;
			}
		}
		if(!fadeIn && alpha <= 254)
		{			
			alpha += _fadeRate * (deltaTicks/1000.f);
			
			if (alpha >= 254) {fading = false;}		
		}
	}		
}

void BlackScreen::SetToFadeOut()
{	
	fading = true;
	fadeIn = false;
}

void BlackScreen::Clear()
{
	alpha = 0;
}

bool BlackScreen::FullAlpha()
{
	return alpha >= 254;
}

