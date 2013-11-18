#include "Projectile.h"

Projectile::Projectile()
{
	Location = Vector2f(0.0f, 0.0f);

	Speed = 55.0f;

	frame = 0;
}

void Projectile::SetProjectileRenderer(SDL_Renderer* renderer)
{
	projRenderer = renderer;
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
	Location.x++;
	Location.y++;
}

void Projectile::Draw(SDL_Renderer* renderer)
{
  	Render(Location, renderer, &SpriteClips[frame]);

	++frame;

	if (frame >= FIRE_FRAMES)
	{
		frame = 0;
	}
}