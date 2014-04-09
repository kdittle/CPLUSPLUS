#ifndef PLAYER_H
#define PLAYER_H

#include "Headers.h"
#include "KinematicEntity.h"
#include "Spell.h"
#include <list>

class Player : public KinematicEntity
{
	float mMoveSpeed;

	typedef KinematicEntity Base;

public:
	static const int WALKING_FRAMES = 4;	//Frames for sprite clips
	SDL_Rect SpriteClips[WALKING_FRAMES];	//Sprite clips for animation
	Spell spell;							//Spell. Plan to add more. Maybe store in a data structure
	SDL_Rect healthRec;						//Health rectangle for health bar
	float healthPercent;					//Percent of health left
	SDL_Rect manaRec;						//Mana rectangle for mana bar
	float manaPercent;						//Percent of mana left

	static Player* Instance();				//Player instance

	Player();								//Constructor

	void SetSpriteClips();					//Set sprite clips for animation
	void Update(float deltaTime);			//Update Player
	void Draw();							//Render Player
	void LoadSpells();						//Load spells and sprites and maps them to a key
	Vector2f<float> GetPlayerLocation();	//Return player Location
	void SetBoundingBox();					//Shift bounding box for collision

	float GetHealth();						//Return health left
	void SetHealthRec();					//Sets up the health rectangle
	void UpdateHealthRec(float dmg);		//Update the health bar
	float GetHealthPercent();				//Returns health percent for use in health rectangle

	float GetMana();						//Return mana
	void SetManaRec();						//Sets up mana rectangle
	void UpdateManaRec(float manaUsed);		//Update mana bar
	float GetManaPercent();					//Returns mana percent for use in mana rectangle
	float GetMaxMana();						//Returns max mana

	int frame;								//Frame for animation
	bool isPlaying;							//Determine if the player is playing

	bool left, right, up, down, cast;		//Determine movement and casting

private:
	float m_health;
	float m_curHealth;
	float m_mana;
	float m_curMana;
	float playWidth;
	float playHeight;

};


#endif