#include "Spell.h"

Spell::Spell()
{
	Location = Vector2f(0.0f, 0.0f);

	Speed = 55.0f;

	frame = 0;
}

void Spell::SetSpellRenderer(SDL_Renderer* renderer)
{
	sRenderer = renderer;
}

void Spell::SetSpriteClips()
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

void Spell::Update(float deltaTime, Vector2f position)
{
	Draw(position);

	Base::Update(deltaTime);
}

void Spell::Draw(Vector2f position)
{
	position.x = position.x - 29;
	position.y = position.y - 15;
	Render(position, sRenderer);

	++frame;

	if (frame >= FIRE_FRAMES)
	{
		frame = 0;
	}
}