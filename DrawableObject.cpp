#include "DrawableObject.h"

Vector2D DrawableObject::Center()
{
	Vector2D center(x + (width/2),y + (height/2));	
	return center;
}

void DrawableObject::SetIsActive(bool activity)
{
	isActive = activity;
}

bool DrawableObject::GetIsActive()
{
	return isActive;
}
