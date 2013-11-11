#include "Player.h"
#include "Vector2f.h"

Player::Player()
{
	Location = Vector2f (25.0f, 550.0f);

	mMoveSpeed = 5.0f;

	IsMoving = true;
}

void Player::Update(float deltaTime)
{
	bool
		left = false,
		right = false,
		up = false,
		down = false;

	SDL_Event event;

	SDL_PumpEvents();

	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case(SDL_KEYDOWN) :
			{
				std::cout << "Keydown" << std::endl;

				if(event.key.keysym.sym == SDLK_LEFT)
				{
					left = true;

					//Location.x -= mMoveSpeed * deltaTime;
				}
				if(event.key.keysym.sym == SDLK_RIGHT)
					right = true;
				if(event.key.keysym.sym == SDLK_UP)
					up = true;
				if(event.key.keysym.sym == SDLK_DOWN)
					down = true;

				break;
			}
		case(SDL_KEYUP) :
			{
				std::cout << "Keyup" << std::endl;

				if(event.key.keysym.sym == SDLK_LEFT)
				{
					left = false;

					//Location.x += mMoveSpeed * deltaTime;
				}
				if(event.key.keysym.sym == SDLK_RIGHT)
					right = false;
				if(event.key.keysym.sym == SDLK_UP)
					up = false;
				if(event.key.keysym.sym == SDLK_DOWN)
					down = false;

				break;
			}
		}
	}

	if(left)
	{
		Location.x -= mMoveSpeed * deltaTime;
		std::cout << Location.x << " " << Location.y << std::endl;
	}

	if(right)
	{
		Location.x += mMoveSpeed * deltaTime;
		std::cout << Location.x << " " << Location.y << std::endl;
	}

	if(up)
	{
		Location.y -= mMoveSpeed * deltaTime;
		std::cout << Location.x << " " << Location.y << std::endl;
	}

	if(down)
	{
		Location.y += mMoveSpeed * deltaTime;
		std::cout << Location.x << " " << Location.y << std::endl;
	}

	if(Location.x >= 775)
		Location.x = 775;
	if(Location.x <= 25)
		Location.x = 25;

	if(Location.y >= 575)
		Location.y = 575;
	if(Location.y <= 25)
		Location.y = 25;

	Base::Update(deltaTime);
}