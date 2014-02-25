#include "GameObject.h"


void GameObject::Load(char* filename)
{
	m_pSprite = Sprite::Load(filename); // use our sprite class to load the image
	printf("GameObject Init Successful\n");	
}

void GameObject::Update()
{
	// nothing for now
}

void GameObject::Draw(SDL_Surface* surface)
{	
	Sprite::Draw(surface, m_pSprite, position.x, position.y);	
}

void GameObject::Clean()
{
    SDL_FreeSurface(m_pSprite); // free the surface
}



