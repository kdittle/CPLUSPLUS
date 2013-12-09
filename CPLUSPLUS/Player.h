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

	SDL_Surface* tScreen;
	SDL_Window* tWindow;

	SDL_Renderer* pRenderer;

	Player();
	
	void SetPlayerRenderer(SDL_Renderer* renderer);
	void SetSpriteClips();
	void Update(float deltaTime);
	void Draw();
	void LoadSpells();
	Vector2f GetPlayerLocation();
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