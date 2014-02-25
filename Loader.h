#ifndef LOADER_H
#define LOADER_H

class Loader
{
	public:
		Update();
		Draw(Game* game);
			
	private:
		std::list<const char*> filesToLoad;
		std::map<const char*,SDL_Surface*> spriteMap;
		std::map<const char*,Mix_Chunk*> soundMap;
};
