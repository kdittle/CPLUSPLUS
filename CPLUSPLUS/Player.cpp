#include "Player.h"

//Set up and instance of the player
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
	//Renders top left corner at 400, 300.
	//To render full center must subtract half width and half height
	Location = Vector2f<float>(400.0f - 30.0f, 300.0f - 50.0f);

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

	if (input.KeyboardInput() == 2)
		up = true;
	if (input.KeyboardInput() == 3)
		down = true;
	if (input.KeyboardInput() == 4)
		left = true;
	if (input.KeyboardInput() == 5)
		right = true;



	////The following code is all input code
	//SDL_Event event;

	//SDL_PumpEvents();

	//while(SDL_PollEvent(&event))
	//{
	//	switch(event.type)
	//	{
	//	case (SDL_QUIT):
	//		{		 
	//			isPlaying = false;
	//			break;
	//		}

	//	case(SDL_KEYDOWN) :
	//		{
	//			std::cout << "Keydown" << std::endl;

	//			if (event.key.keysym.sym == SDLK_ESCAPE)
	//				isPlaying = false;

	//			if (event.key.keysym.sym == SDLK_LEFT)
	//			{
	//				this->Location._x -= mMoveSpeed * deltaTime;
	//				left = true;
	//				std::cout << this->Location._x << " " << this->Location._y << std::endl;
	//			}
	//			if (event.key.keysym.sym == SDLK_RIGHT)
	//			{
	//				this->Location._x += mMoveSpeed * deltaTime;
	//				right = true;
	//				std::cout << this->Location._x << " " << this->Location._y << std::endl;
	//			}
	//			if (event.key.keysym.sym == SDLK_UP)
	//			{
	//				this->Location._y -= mMoveSpeed * deltaTime;
	//				up = true;
	//				std::cout << this->Location._x << " " << this->Location._y << std::endl;
	//			}
	//			if (event.key.keysym.sym == SDLK_DOWN)
	//			{
	//				this->Location._y += mMoveSpeed * deltaTime;
	//				down = true;
	//				std::cout << this->Location._x << " " << this->Location._y << std::endl;
	//			}

	//			if (event.key.keysym.sym == SDLK_SPACE)
	//			{
	//				cast = true;
	//			}

	//			break;
	//		}
	//	case(SDL_KEYUP) :
	//		{
	//			std::cout << "Keyup" << std::endl;

	//			if (event.key.keysym.sym == SDLK_LEFT)
	//			{
	//				this->Location._x = this->Location._x;
	//				left = false;
	//			}
	//			if (event.key.keysym.sym == SDLK_RIGHT)
	//			{
	//				this->Location._x = this->Location._x;
	//				right = false;
	//			}
	//			if (event.key.keysym.sym == SDLK_UP)
	//			{
	//				this->Location._y = this->Location._y;
	//				up = false;
	//			}
	//			if (event.key.keysym.sym == SDLK_DOWN)
	//			{
	//				this->Location._y = this->Location._y;
	//				down = false;
	//			}
	//			if (event.key.keysym.sym == SDLK_SPACE)
	//			{
	//				cast = false;
	//			}

	//			break;
	//		}
	//	}
	//}

	//Clamp to window code 
	//Needs to be modified some
	if(this->Location._x >= 755)
		this->Location._x = 755;
	if(this->Location._x <= 10)
		this->Location._x = 10;

	if(this->Location._y >= 550)
		this->Location._y = 550;
	if(this->Location._y <= 10)
		this->Location._y = 10;

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

	if (right)
		frame = 3;

	if (up)
		frame = 1;

	if (down)
		frame = 0;

	Render(this->Location, &SpriteClips[frame]);

	/*SDL_SetRenderDrawColor(pRenderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderDrawRect(pRenderer, &m_BoundingBox);*/

	SetHealthRec();
}

void Player::LoadSpells()
{
	//Load the spells and set their clips and bounding boxes
	spell.LoadFromFile("RingOfFireSpriteSheet.png");
	spell.SetSpriteClips();
	spell.SetBoundingBox(this->Location);
	spells.push_back(spell);


	spell.LoadFromFile("Fireball.png");
	spell.SetBoundingBox(this->Location);
	spells.push_back(spell);

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
	SDL_Surface* rectSurface = NULL;

	healthPercent = GetHealthPercent();
	float visible = healthRec.w * healthPercent;

	healthRec.x = this->Location._x + 5;
	healthRec.y = this->Location._y + getHeight();
	healthRec.w = 50.0f;
	healthRec.h = 10.0f;

	//rectSurface = SDL_CreateRGBSurface(SDL_SWSURFACE, healthRec.w, healthRec.h, 32, 0, 0x80, 0, 0);

	//rectSurface = SDL_CreateRGBSurface(SDL_SWSURFACE, healthRec.w, healthRec.h, 32, 0, 0, 0, 0);

	//SDL_SetRenderDrawColor(pRenderer, 0x00, 0x00, 0x00, 0xFF);
	//SDL_RenderDrawRect(pRenderer, &healthRec);

	//SDL_FillRect(tScreen, &healthRec, SDL_MapRGB(rectSurface->format, 0x00, 0x80, 0x00));

	//SDL_FillRect(tScreen, &healthRec, SDL_MapRGB(rectSurface->format, 0x00, 0x00, 0x00));

	//SDL_RenderFillRect(pRenderer, &healthRec);


}

float Player::GetHealthPercent()
{
	return (GetHealth() / m_health);
}