#include "Enemy.h"

Enemy::Enemy()
{
	moveSpeed = 50;
}

void Enemy::SetEnemyRenderer(SDL_Renderer* renderer)
{
	eRenderer = renderer;
}

void Enemy::Update(float deltaTime)
{
	Draw();

	Base::Update(deltaTime);
}

void Enemy::Draw()
{
	Render(Location, eRenderer);
}