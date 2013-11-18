#include "Projectile.h"

Projectile::Projectile()
{
	Speed = 55.0f;

	frame = 0;
}

void Projectile::SetSpriteClips()
{
	SpriteClips[0].x = 0;
	SpriteClips[0].y = 0;
	SpriteClips[0].w = 30;
	SpriteClips[0].h = 30;

	SpriteClips[0].x = 28;
	SpriteClips[0].y = 0;
	SpriteClips[0].w = 30;
	SpriteClips[0].h = 30;

	SpriteClips[0].x = 59;
	SpriteClips[0].y = 0;
	SpriteClips[0].w = 30;
	SpriteClips[0].h = 30;
}

void Projectile::Update(float deltaTime)
{
	Base::Update(deltaTime);

	
}

void Projectile::Draw(SDL_Renderer* renderer, float deltaTime)
{
	Render(Location, renderer, &SpriteClips[frame]);

	SDL_Delay(300 * deltaTime);

	++frame;

	if (frame / 3 >= FIRE_FRAMES)
	{
		frame = 0;
	}
}