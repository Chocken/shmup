#include "SpriteFactory.h"

void SpriteFactory::Init()
{
	SDL_Surface* background = Sprite::Load(const_cast<char *>("bg.png"), false);
	SDL_Surface* playerShip = Sprite::Load(const_cast<char *>("NewShip.png"), true);
	SDL_Surface* blackScreen = Sprite::Load(const_cast<char *>("blackScreen.png"), false);
	SDL_Surface* explosion = Sprite::Load(const_cast<char *>("explosions.png"), true);
	SDL_Surface* asteroid = Sprite::Load(const_cast<char *>("asteroid.png"), true);
	SDL_Surface* projectile = Sprite::Load(const_cast<char *>("projectile.png"), true);
	SDL_Surface* enemy = Sprite::Load(const_cast<char *>("enemy1.png"), true);

	spriteMap["background"] = background;
	spriteMap["playerShip"] = playerShip;
	spriteMap["blackScreen"] = blackScreen;
	spriteMap["explosions"] = explosion;
	spriteMap["asteroid"] = asteroid;
	spriteMap["projectile1"] = projectile;
	spriteMap["enemy1"] = enemy;
}
