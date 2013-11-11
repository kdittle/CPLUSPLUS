#include "Player.h"
#include "Vector2f.h"

Player::Player()
{
	Location = Vector2f (25.0f, 565.0f);

	LoadFromFile("Thing.png");

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
				if(event.key.keysym.sym == SDLK_LEFT)
					left = true;
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
				if(event.key.keysym.sym == SDLK_LEFT)
					left = false;
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
		Location.x -= Velocity.x * deltaTime;
		std::cout << Location.x << " " << Location.y << std::endl;
	}

	if(right)
	{
		Location.x += Velocity.x * deltaTime;
		std::cout << Location.x << " " << Location.y << std::endl;
	}

	if(up)
	{
		Location.y -= Velocity.y * deltaTime;
		std::cout << Location.x << " " << Location.y << std::endl;
	}

	if(down)
	{
		Location.y += Velocity.y * deltaTime;
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

}

void Player::Draw(SDL_Window* targetWindow)
{
	Base::Draw(targetWindow);
}