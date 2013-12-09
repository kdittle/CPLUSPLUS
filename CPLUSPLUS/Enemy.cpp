#include "Enemy.h"

Enemy::Enemy()
{
	Location = Vector2f(200.0f, 200.0f);

	moveSpeed = 50;

	frame = 0;

	chasing = false;
	caught = false;

	left = false;
	right = false;
	up = false;
	down = false;

	m_health = 20.0f;
}

void Enemy::SetEnemyRenderer(SDL_Renderer* renderer)
{
	eRenderer = renderer;
}

void Enemy::PlayerReference(Player& player)
{
	rPlayer = player;
}

void Enemy::SetSpriteClips()
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

void Enemy::Update(float deltaTime)
{
	Vector2f movementVector = Vector2f(0.0f, 0.0f);

	if(this->Location.x != playerLocation.x && this->Location.y != playerLocation.y)
	{
		chasing = true;
	}

	if(chasing)
	{
		playerLocation = rPlayer.GetPlayerLocation();
		movementVector.x = (playerLocation.x - this->Location.x);
		movementVector.y = (playerLocation.y - this->Location.y);

		movementVector.normalize();

		this->Location.x += movementVector.x;
		this->Location.y += movementVector.y;
	}

	if(this->Location.x == playerLocation.x || this->Location.y == playerLocation.y)
	{
		caught = true;
	}

	if(caught)
	{
		movementVector = Vector2f(0.0f, 0.0f);
	}

	if(this->Location.x < rPlayer.Location.x)
	{
		right = true;
		left = false;
	}

	if(this->Location.x > rPlayer.Location.x)
	{
		left = true;
		right = false;
	}

	shiftBoundingBox();
	Draw();

	Base::Update(deltaTime);
}

void Enemy::Draw()
{
	if(left)
		frame = 2;

	if(right)
		frame = 3;

	Render(this->Location, eRenderer, &SpriteClips[frame]);

	/*SDL_SetRenderDrawColor(eRenderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderDrawRect(eRenderer, &m_BoundingBox);*/
}

void Enemy::SetBoundingBox()
{
	m_BoundingBox.x = this->Location.x;
	m_BoundingBox.y = this->Location.y;
	m_BoundingBox.w = getWidth() / 4;
	m_BoundingBox.h = getHeight();
}

float Enemy::GetHealth()
{
	return m_health;
}