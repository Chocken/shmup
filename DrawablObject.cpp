DrawableObject::DrawableObject()
{
	stopDrawing = false;
}

void DrawableObject::Fade(int fadeby)
{
	alpha -= fadeby;
}

Vector2D DrawableObject::Center()
{
	Vector2D center(x + (width/2),y + (height/2));
	return center;
}


