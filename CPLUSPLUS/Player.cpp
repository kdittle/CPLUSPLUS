#include "Player.h"

Player::Player()
{
	Location = Vector2f (400.0f, 300.0f);

	mMoveSpeed = 45.0f;

	frame = 0;

	isPlaying = true;

	left = false;
	right = false;
	up = false;
	down = false;
	cast = false;
}

void Player::SetPlayerRenderer(SDL_Renderer* renderer)
{
	playerRenderer = renderer;
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
					Location.x -= mMoveSpeed * deltaTime;
					left = true;
				}
				if (event.key.keysym.sym == SDLK_RIGHT)
				{
					Location.x += mMoveSpeed * deltaTime;
					right = true;
				}
				if (event.key.keysym.sym == SDLK_UP)
				{
					Location.y -= mMoveSpeed * deltaTime;
					up = true;
				}
				if (event.key.keysym.sym == SDLK_DOWN)
				{
					Location.y += mMoveSpeed * deltaTime;
					down = true;
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
					Location.x = Location.x;
					left = false;
				}
				if (event.key.keysym.sym == SDLK_RIGHT)
				{
					Location.x = Location.x;
					right = false;
				}
				if (event.key.keysym.sym == SDLK_UP)
				{
					Location.y = Location.y;
					up = false;
				}
				if (event.key.keysym.sym == SDLK_DOWN)
				{
					Location.y = Location.y;
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


	if(Location.x >= 755)
		Location.x = 755;
	if(Location.x <= 10)
		Location.x = 10;

	if(Location.y >= 550)
		Location.y = 550;
	if(Location.y <= 10)
		Location.y = 10;

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

	Render(Location, playerRenderer, &SpriteClips[frame]);

}