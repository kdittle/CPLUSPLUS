#include "Enemy.h"

Enemy::Enemy()
{
	Location = Vector2f<float>(200.0f, 200.0f);

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

//void Enemy::SetEnemyRenderer(SDL_Renderer* renderer)
//{
//	eRenderer = renderer;
//}
//
//void Enemy::PlayerReference(Player& player)
//{
//	rPlayer = player;
//}

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
	Vector2f<float> movementVector = Vector2f<float>(0.0f, 0.0f);

	if(this->Location._x != playerLocation._x && this->Location._y != playerLocation._y)
	{
		chasing = true;
	}

	if(chasing)
	{
		playerLocation = rPlayer.GetPlayerLocation();
		movementVector._x = (playerLocation._x - this->Location._x);
		movementVector._y = (playerLocation._y - this->Location._y);

		movementVector.normalize();

		this->Location._x += movementVector._x;
		this->Location._y += movementVector._y;
	}

	if(this->Location._x == playerLocation._x || this->Location._y == playerLocation._y)
	{
		caught = true;
	}

	if(caught)
	{
		movementVector = Vector2f<float>(0.0f, 0.0f);
	}

	if(this->Location._x < rPlayer.Location._x)
	{
		right = true;
		left = false;
	}

	if(this->Location._x > rPlayer.Location._x)
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

	Render(this->Location, mRenderer/*eRenderer*/, &SpriteClips[frame]);

	/*SDL_SetRenderDrawColor(eRenderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderDrawRect(eRenderer, &m_BoundingBox);*/
}

void Enemy::SetBoundingBox()
{
	m_BoundingBox.x = this->Location._x;
	m_BoundingBox.y = this->Location._y;
	m_BoundingBox.w = getWidth() / 4;
	m_BoundingBox.h = getHeight();
}

float Enemy::GetHealth()
{
	return m_health;
}