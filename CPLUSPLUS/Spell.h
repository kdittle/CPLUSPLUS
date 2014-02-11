#ifndef SPELL_H
#define SPELL_H

#include "Headers.h"
#include "GameEntity.h"
#include "CollisionDetection.h"

class Spell : public GameEntity
{
	typedef GameEntity Base;

public:
	float Speed;
	SDL_Renderer* sRenderer;
	static const int FIRE_FRAMES = 2;
	SDL_Rect SpriteClips[FIRE_FRAMES];
	CollisionDetection collisionHandler;


	Spell();

	void SetSpellRenderer(SDL_Renderer* renderer);
	void SetSpriteClips();
	void Update(float deltaTime, Vector2f<float> position);
	void Draw(Vector2f<float> position);
	void SetBoundingBox(Vector2f<float> position);
	bool checkCollision(SDL_Rect player, SDL_Rect enemy);

	int frame;

private:

};

#endif