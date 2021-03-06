#ifndef TEXT_RENDERER_H
#define TEXT_RENDERER_H

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include <string>

class TextRenderer
{
	public:
		TextRenderer();
		TextRenderer(char fontName[], int fontSize, SDL_Color color);
		void SetFont(char fontName[], int fontSize);
		void SetColour(SDL_Color textColor);
		void SetSize(int size);
		void SetText(std::string text);
		void Free();
		void Clear();
		void Draw(SDL_Surface* gameSurface, int x, int y);
	 
	private:
		void Init();
		SDL_Surface* surface;
		char* name;
		int size;
		SDL_Color color;
		TTF_Font* font;		
};

#endif
