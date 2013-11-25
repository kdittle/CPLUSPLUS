#ifndef SPELL_H
#define SPELL_H

#include "Headers.h"
#include "GameEntity.h"

class Spell : public GameEntity
{
	typedef GameEntity Base;

public:
	float Speed;
	SDL_Renderer* sRenderer;
	static const int FIRE_FRAMES = 2;
	SDL_Rect SpriteClips[FIRE_FRAMES];

	Spell();

	void SetSpellRenderer(SDL_Renderer* renderer);
	void SetSpriteClips();
	void Update(float deltaTime, Vector2f position);
	void Draw(Vector2f position);

	int frame;

private:

};

#endif