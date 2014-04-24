#ifndef FIRESHIELD_H
#define FIRESHIELD_H

#include "Headers.h"
#include "Spell.h"

class FireShield : public Spell
{
	typedef Spell Base;

public:

	int frame;
	static const int SPELL_FRAMES = 2;
	SDL_Rect SpriteClips[SPELL_FRAMES];

	FireShield();
	~FireShield();


	void SetSpriteClips();
	void SetBoundingBox();
	void Update(float deltaTime, Vector2f<float> position);
	void Draw(Vector2f<float> position);

private:

protected:


};


#endif