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

void TextRenderer::SetText(std::string text)
{
	surface = TTF_RenderText_Solid(font, const_cast<char *>(text.c_str()), color );
}

void TextRenderer::Init()
{
	font = TTF_OpenFont(name, size);
	if(font == NULL){printf("failed to load font\n");}
}

void TextRenderer::Free()
{
	SDL_FreeSurface(surface);
}

void TextRenderer::Draw(SDL_Surface* gameSurface, int x, int y)
{	
	Sprite::Draw(gameSurface, surface, x, y);	
}

