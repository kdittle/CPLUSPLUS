#ifndef PLAYER_H
#define PLAYER_H

#include "Headers.h"
#include "KinematicEntity.h"
#include "Spell.h"

class Player : public KinematicEntity
{
	float mMoveSpeed;

	typedef KinematicEntity Base;

public:
	static const int WALKING_FRAMES = 4;
	SDL_Rect SpriteClips[WALKING_FRAMES];
	Spell fireShield;
	SDL_Rect healthRec;
	float healthPercent;

	Player();

	void SetSpriteClips();
	void Update(float deltaTime);
	void Draw();
	void LoadSpells();
	Vector2f<float> GetPlayerLocation();
	void SetBoundingBox();
	void LoadHealthBar();
	float GetHealth();
	void SetHealthRec();
	void UpdateHealthRec();
	float GetHealthPercent();

	void ScreenRef(SDL_Surface* surface);
	void WindowRef(SDL_Window* window);

	int frame;
	bool isPlaying;

	bool left, right, up, down, cast;

private:
	float m_health;
	float m_curHealth;
	float playWidth;
	float playHeight;

};


#endif