#include "FireShield.h"	

FireShield::FireShield()
{

	frame = 0;
}

FireShield::~FireShield()
{
	free();
}

void FireShield::SetSpriteClips()
{
	SpriteClips[0].x = 0;
	SpriteClips[0].y = 0;
	SpriteClips[0].w = 100;
	SpriteClips[0].h = 135;

	SpriteClips[1].x = 99;
	SpriteClips[1].y = 0;
	SpriteClips[1].w = 100;
	SpriteClips[1].h = 135;
}

void FireShield::Update(float deltaTime, Vector2f<float> position)
{
	Draw(position);

	shiftBoundingBox();

	Base::Update(deltaTime);
}

void FireShield::Draw(Vector2f<float> position)
{
	if (frame < 2)
		frame++;

	if (frame >= 2)
		frame = 0;

	this->Location = position;
	this->Location._x = Location._x - 20;
	this->Location._y = Location._y - 10;

	Render(this->Location, &SpriteClips[frame]);
} 