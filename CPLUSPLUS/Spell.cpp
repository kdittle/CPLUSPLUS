#include "Spell.h"

Spell::Spell()
{
	Location = Vector2f<float>(0.0f, 0.0f);

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
	SpriteClips[0].w = 101;
	SpriteClips[0].h = 135;

	SpriteClips[1].x = 102;
	SpriteClips[1].y = 0;
	SpriteClips[1].w = 101;
	SpriteClips[1].h = 135;
}

void Spell::Update(float deltaTime, Vector2f<float> position)
{
	Draw(position);

	shiftBoundingBox();

	Base::Update(deltaTime);
}

void Spell::Draw(Vector2f<float> position)
{
	position._x = position._x - 20;
	position._y = position._y - 15;
	Render(position, &SpriteClips[frame]);

	++frame;

	if (frame >= FIRE_FRAMES)
	{
		frame = 0;
	}

	/*SDL_SetRenderDrawColor(sRenderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderDrawRect(sRenderer, &m_BoundingBox);*/
}

void Spell::SetBoundingBox(Vector2f<float> position)
{
	m_BoundingBox.x = position._x - 22.0f;
	m_BoundingBox.y = position._y - 15.0f;
	m_BoundingBox.w = getWidth() / 2.0f;
	m_BoundingBox.h = getHeight();
}

bool Spell::checkCollision(SDL_Rect player, SDL_Rect enemy)
{
	if (collisionHandler.Check_Box_Collision(player, enemy))
	{
		return true;
	}

	return false;
}