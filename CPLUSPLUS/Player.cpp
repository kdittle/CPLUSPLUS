#include "Player.h"

Player::Player()
{
	//Renders top left corner at 400, 300.
	//To render full center must subtract half width and half height
	Location = Vector2f (400.0f - 30.0f, 300.0f - 50.0f);

	mMoveSpeed = 45.0f;

	frame = 0;

	isPlaying = true;

	left = false;
	right = false;
	up = false;
	down = false;
	cast = false;

	m_health = 20.0f;
	m_curHealth = 20.0f;
}

void Player::SetPlayerRenderer(SDL_Renderer* renderer)
{
	pRenderer = renderer;
}

void Player::ScreenRef(SDL_Surface* surface)
{
	tScreen = surface;
}

void Player::WindowRef(SDL_Window* window)
{
	tWindow = window;
}

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

void Player::Update(float deltaTime)
{
	LoadSpells();

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
					this->Location.x -= mMoveSpeed * deltaTime;
					left = true;
					std::cout << this->Location.x << " " << this->Location.y << std::endl;
				}
				if (event.key.keysym.sym == SDLK_RIGHT)
				{
					this->Location.x += mMoveSpeed * deltaTime;
					right = true;
					std::cout << this->Location.x << " " << this->Location.y << std::endl;
				}
				if (event.key.keysym.sym == SDLK_UP)
				{
					this->Location.y -= mMoveSpeed * deltaTime;
					up = true;
					std::cout << this->Location.x << " " << this->Location.y << std::endl;
				}
				if (event.key.keysym.sym == SDLK_DOWN)
				{
					this->Location.y += mMoveSpeed * deltaTime;
					down = true;
					std::cout << this->Location.x << " " << this->Location.y << std::endl;
				}
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
					this->Location.x = this->Location.x;
					left = false;
				}
				if (event.key.keysym.sym == SDLK_RIGHT)
				{
					this->Location.x = this->Location.x;
					right = false;
				}
				if (event.key.keysym.sym == SDLK_UP)
				{
					this->Location.y = this->Location.y;
					up = false;
				}
				if (event.key.keysym.sym == SDLK_DOWN)
				{
					this->Location.y = this->Location.y;
					down = false;
				}
				if (event.key.keysym.sym == SDLK_SPACE)
				{
					cast = false;
				}

				break;
			}
		}
	}

	if(this->Location.x >= 755)
		this->Location.x = 755;
	if(this->Location.x <= 10)
		this->Location.x = 10;

	if(this->Location.y >= 550)
		this->Location.y = 550;
	if(this->Location.y <= 10)
		this->Location.y = 10;

	shiftBoundingBox();
	Draw();

	Base::Update(deltaTime);
}

void Player::Draw()
{

	if (left)
		frame = 2;

	if (right)
		frame = 3;

	if (up)
		frame = 1;

	if (down)
		frame = 0;

	Render(this->Location, pRenderer, &SpriteClips[frame]);

	/*SDL_SetRenderDrawColor(pRenderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderDrawRect(pRenderer, &m_BoundingBox);*/

	SetHealthRec();
}

void Player::LoadSpells()
{
	fireShield.LoadFromFile("RingOfFireSpriteSheet.png", pRenderer);
	fireShield.SetSpellRenderer(pRenderer);
	fireShield.SetSpriteClips();
	fireShield.SetBoundingBox(this->Location);
}

Vector2f Player::GetPlayerLocation()
{
	return this->Location;
}

void Player::SetBoundingBox()
{
	m_BoundingBox.x = this->Location.x;
	m_BoundingBox.y = this->Location.y;
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

	healthRec.x = this->Location.x + 5;
	healthRec.y = this->Location.y + getHeight();
	healthRec.w = 50.0f;
	healthRec.h = 10.0f;

	rectSurface = SDL_CreateRGBSurface(SDL_SWSURFACE, healthRec.w, healthRec.h, 32, 0, 0, 0, 0);

	SDL_SetRenderDrawColor(pRenderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderDrawRect(pRenderer, &healthRec);

	SDL_FillRect(tScreen, &healthRec, SDL_MapRGB(rectSurface->format, 0x00, 0x00, 0x00));

	SDL_RenderFillRect(pRenderer, &healthRec);


}

float Player::GetHealthPercent()
{
	return (GetHealth() / m_health);
}