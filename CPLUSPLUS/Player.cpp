#include "Player.h"

//Set up an instance of the player
Player* Player::Instance()
{
	static Player* instance = nullptr;

	if (instance == nullptr)
		instance = new Player();

	return instance;
}

//Set player defaults
Player::Player()
{
	//Render at middle bottom of the screen
	Location = Vector2f<float>(GameEntity::WINDOW_WIDTH / 2 - this->getWidth(), GameEntity::WINDOW_HEIGHT - 100);

	LoadFromFile("WizardSpriteSheet2.png");
	SetSpriteClips();
	SetBoundingBox();

	mMoveSpeed = 45.0f;

	frame = 0;

	isPlaying = true;

	left = false;
	right = false;
	up = false;
	down = false;
	cast = false;

	LoadSpells();

	m_health = 20.0f;
	m_curHealth = 20.0f;

	m_mana = 10.0f;
	m_curMana = 10.0f;
}

//Set sprite clips for animation
void Player::SetSpriteClips()
{
	SpriteClips[0].x = 0;
	SpriteClips[0].y = 0;
	SpriteClips[0].w = 60;
	SpriteClips[0].h = 100;

	SpriteClips[1].x = 59;
	SpriteClips[1].y = 0;
	SpriteClips[1].w = 60;
	SpriteClips[1].h = 100;

	SpriteClips[2].x = 119;
	SpriteClips[2].y = 0;
	SpriteClips[2].w = 60;
	SpriteClips[2].h = 100;

	SpriteClips[3].x = 177;
	SpriteClips[3].y = 0;
	SpriteClips[3].w = 60;
	SpriteClips[3].h = 100;
}

//Update
void Player::Update(float deltaTime)
{


	//The following code is all input code
	SDL_Event event;

	SDL_PumpEvents();

	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case (SDL_QUIT):
			{		 
				isPlaying = false;
				break;
			}

		case(SDL_KEYDOWN) :
			{
				std::cout << "Keydown" << std::endl;

				if (event.key.keysym.sym == SDLK_ESCAPE)
					isPlaying = false;

				if (event.key.keysym.sym == SDLK_LEFT)
				{
					this->Location._x -= mMoveSpeed * deltaTime;
					left = true;
					std::cout << this->Location._x << " " << this->Location._y << std::endl;
				}
				if (event.key.keysym.sym == SDLK_RIGHT)
				{
					this->Location._x += mMoveSpeed * deltaTime;
					right = true;
					std::cout << this->Location._x << " " << this->Location._y << std::endl;
				}
				//if (event.key.keysym.sym == SDLK_UP)
				//{
				//	this->Location._y -= mMoveSpeed * deltaTime;
				//	up = true;
				//	std::cout << this->Location._x << " " << this->Location._y << std::endl;
				//}
				//if (event.key.keysym.sym == SDLK_DOWN)
				//{
				//	this->Location._y += mMoveSpeed * deltaTime;
				//	down = true;
				//	std::cout << this->Location._x << " " << this->Location._y << std::endl;
				//}

				if (event.key.keysym.sym == SDLK_SPACE)
				{
					cast = true;
				}

				break;
			}
		case(SDL_KEYUP) :
			{
				std::cout << "Keyup" << std::endl;

				if (event.key.keysym.sym == SDLK_LEFT)
				{
					this->Location._x = this->Location._x;
					left = false;
				}
				if (event.key.keysym.sym == SDLK_RIGHT)
				{
					this->Location._x = this->Location._x;
					right = false;
				}
				//if (event.key.keysym.sym == SDLK_UP)
				//{
				//	this->Location._y = this->Location._y;
				//	up = false;
				//}
				//if (event.key.keysym.sym == SDLK_DOWN)
				//{
				//	this->Location._y = this->Location._y;
				//	down = false;
				//}
				if (event.key.keysym.sym == SDLK_SPACE)
				{
					cast = false;
				}

				break;
			}
		}
	}

	if (m_curMana < 0)
		cast = false;

	if (cast)
		fireshield.Update(deltaTime, this->Location);

	//Clamp to window code 
	//Needs to be modified some
	if (this->Location._x >= (GameEntity::WINDOW_WIDTH - this->getWidth() / 4))
		this->Location._x = (GameEntity::WINDOW_WIDTH - this->getWidth () / 4);
	if(this->Location._x <= 0)
		this->Location._x = 0;

	//if(this->Location._y >= 550)
	//	this->Location._y = 550;
	//if(this->Location._y <= 10)
	//	this->Location._y = 10;

	//Shift the bounding box for collision and render
	shiftBoundingBox();
	Draw();

	Base::Update(deltaTime); //Update the base
}

void Player::Draw()
{
	//Determine what way the player is moving, set that as the frame, then render

	if (left)
		frame = 2;

	else if (right)
		frame = 3;
	else
		frame = 1;

	/*if (up)
		frame = 1;

	if (down)
		frame = 0;*/

	Render(this->Location, &SpriteClips[frame]);

	/*SDL_SetRenderDrawColor(pRenderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderDrawRect(pRenderer, &m_BoundingBox);*/

	SetHealthRec();
	SetManaRec();
}

void Player::LoadSpells()
{
	fireshield.LoadFromFile("RingOfFireSpriteSheet.png");
	fireshield.SetSpriteClips();
}

Vector2f<float> Player::GetPlayerLocation()
{
	return this->Location;
}

void Player::SetBoundingBox()
{
	m_BoundingBox.x = this->Location._x;
	m_BoundingBox.y = this->Location._y;
	m_BoundingBox.w = getWidth() / 4;
	m_BoundingBox.h = getHeight();
}

float Player::GetHealth()
{
	return m_curHealth;
}

void Player::SetHealthRec()
{

	healthPercent = GetHealthPercent();
	float visible = healthRec.w * healthPercent;

	if (healthPercent < 0)
		visible = 0;

	healthRec.x = 5.0f;
	healthRec.y = 5.0f;
	healthRec.w = 100.0f;
	healthRec.h = 10.0f;

	SDL_Rect curHealthRec;
	curHealthRec.x = 5.0f;
	curHealthRec.y = 5.0f;
	curHealthRec.w = visible;
	curHealthRec.h = 10.0f;

	SDL_SetRenderDrawColor(GameEntity::GetRenderer(), 0x00, 0x80, 0x00, 0xFF);
	SDL_RenderDrawRect(GameEntity::GetRenderer(), &healthRec);

	SDL_RenderFillRect(GameEntity::GetRenderer(), &curHealthRec);

}

float Player::GetHealthPercent()
{
	return (GetHealth() / m_health);
}

void Player::UpdateHealthRec(float dmg)
{
	m_curHealth = this->GetHealth() - dmg;
}

float Player::GetMana()
{
	return m_curMana;
}

float Player::GetMaxMana()
{
	return m_mana;
}

void Player::SetManaRec()
{
	manaPercent = GetManaPercent();
	float visible = manaRec.w * manaPercent;

	manaRec.x = 5.0f;
	manaRec.y = 15.0f;
	manaRec.w = 100.0f;
	manaRec.h = 10.0f;

	SDL_Rect curManaRec;
	curManaRec.x = 5.0f;
	curManaRec.y = 15.0f;
	curManaRec.w = visible;
	curManaRec.h = 10.0f;

	SDL_SetRenderDrawColor(GameEntity::GetRenderer(), 0x00, 0x00, 0x80, 0xFF);
	SDL_RenderDrawRect(GameEntity::GetRenderer(), &manaRec);

	SDL_RenderFillRect(GameEntity::GetRenderer(), &curManaRec);
}

void Player::UpdateManaRec(float manaUsed)
{
	m_curMana = this->GetMana() - manaUsed;
}

float Player::GetManaPercent()
{
	return (GetMana() / m_mana);
}