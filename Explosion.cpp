#include "Explosion.h"
#include <iostream>

Explosion::Explosion(){}

Explosion::Explosion(Vector2D CenterLocation, int Width, int Height)
{
	sheet = Vector2D(0,0);
	sheetVector = Vector2D(0,0);	
	width = Width;
	height = Height;
	x = CenterLocation.x - (width/2);
	y = CenterLocation.y - (height/2);	
	timer.start();	
}

Explosion::Explosion(const Explosion &explosion)
{
	*sprite = *explosion.sprite;
	height = explosion.height;
	width = explosion.width;
	x = explosion.x;
	y = explosion.y;
	isActive = explosion.isActive;
	drawCenter = explosion.drawCenter;
	sheetVector = explosion.sheetVector;
	finished = explosion.finished;
	frames = explosion.frames;
	drawVector = explosion.drawVector;
	timer = explosion.timer;
	sheet = explosion.sheet;
}

void Explosion::Draw(SDL_Surface* surface)
{	
	if(Sprite::Draw(surface, sprite, x, y, sheetVector.x, sheetVector.y, width, height) == false )printf("failed to draw explosion\n");
}

void Explosion::Update(Uint32 deltaTicks)
{	
	
	sheet.x = ((timer.get_ticks() * 30 / 1000) % 12);
	
	sheetVector.x = sheet.x * width;	
	
	if(sheet.x == frames)
	{
		isActive = false;
	}
}
