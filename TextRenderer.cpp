#include "TextRenderer.h"
#include "Sprite.h"


TextRenderer::TextRenderer(){}

TextRenderer::TextRenderer(char fontName[], int fontSize, SDL_Color textColor)
{
	name = fontName;	
	color = textColor;
	size = fontSize;	
	Init();
}

void TextRenderer::SetFont(char fontName[], int fontSize)
{
	name = fontName;
	size = fontSize;
	Init();
}

void TextRenderer::SetColour(SDL_Color textColor)
{
	textColor = color;
}

void TextRenderer::Init()
{
	font = TTF_OpenFont(name, size);
	if(font == NULL){printf("failed to load font\n");}
}

void TextRenderer::Draw(SDL_Surface* gameSurface, char text[], int x, int y)
{
	surface = TTF_RenderText_Solid(font, text, color );
	Sprite::Draw(gameSurface, surface, x, y);
	SDL_FreeSurface(surface);
}

