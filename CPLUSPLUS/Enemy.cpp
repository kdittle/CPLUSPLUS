#include "Enemy.h"

//Enemy defaults
Enemy::Enemy()
{
	LoadFromFile("EvilWizardSpriteSheet.png");
	SetSpriteClips();
	SetBoundingBox();

	moveSpeed = 50;

	frame = 0;

	chasing = false;
	caught = false;

	left = false;
	right = false;
	up = false;
	down = false;

	m_health = 20.0f;
	m_curHealth = 20.0f;
}

//Sprite clips for animation
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
	//Create a movement vector
	Vector2f<float> movementVector = Vector2f<float>(0.0f, 1.0f * moveSpeed);

	movementVector.normalize();

	this->Location = this->Location + movementVector;

	//Check to see if the enemy location is equal to the player location.
	//If it isn't then it is chasing the enemy
	//if (this->Location._x != Player::Instance()->GetPlayerLocation()._x && this->Location._y != Player::Instance()->GetPlayerLocation()._y)
	//{
	//	chasing = true;
	//}

	////If enemy is chasting, move it towards the player
	//if(chasing)
	//{
	//	movementVector._x = (Player::Instance()->GetPlayerLocation()._x - this->Location._x);
	//	movementVector._y = (Player::Instance()->GetPlayerLocation()._y - this->Location._y);

	//	movementVector.normalize();

	//	this->Location._x += movementVector._x;
	//	this->Location._y += movementVector._y;

	//	std::cout << "Enemy: " << Location._x << "," << Location._y << std::endl;
	//}

	////If enemy and player locations are equal, plays is caught, stop chasing.
	//if (this->Location._x == Player::Instance()->GetPlayerLocation()._x || this->Location._y == Player::Instance()->GetPlayerLocation()._y)
	//{
	//	caught = true;
	//}

	////Stop the movement is player is caught
	//if(caught)
	//{
	//	movementVector = Vector2f<float>(0.0f, 0.0f);
	//}

	////Determine if the player is moving left or right
	//if (this->Location._x < Player::Instance()->GetPlayerLocation()._x)
	//{
	//	right = true;
	//	left = false;
	//}

	//if (this->Location._x > Player::Instance()->GetPlayerLocation()._x)
	//{
	//	left = true;
	//	right = false;
	//}

	//Shift boxes for collision and render
	shiftBoundingBox();
	Draw();

	//Base::Update(deltaTime);
}

void Enemy::Draw()
{
	//Determine if the enemy is moving left or right and render

	frame = 0;

	Render(this->Location, &SpriteClips[frame]);

	/*SDL_SetRenderDrawColor(eRenderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderDrawRect(eRenderer, &m_BoundingBox);*/

	SetHealthRec();
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
	return m_curHealth;
}

void Enemy::SetHealthRec()
{
	/*healthPercent = GetHealthPercent();
	float visible = healthRec.w * healthPercent;

	healthRec.x = this->Location._x + 5;
	healthRec.y = this->Location._y + getHeight();
	healthRec.w = 50.0f;
	healthRec.h = 10.0f;

	SDL_Rect curHealthRec;
	curHealthRec.x = this->Location._x + 5;
	curHealthRec.y = this->Location._y + getHeight();
	curHealthRec.w = visible;
	curHealthRec.h = 10.0f;

	SDL_SetRenderDrawColor(GameEntity::GetRenderer(), 0x00, 0x80, 0x00, 0xFF);
	SDL_RenderDrawRect(GameEntity::GetRenderer(), &healthRec);

	SDL_RenderFillRect(GameEntity::GetRenderer(), &curHealthRec);*/

}

float Enemy::GetHealthPercent()
{
	return (GetHealth() / m_health);
}

void Enemy::UpdateHealthRec(float dmg)
{
	m_curHealth = this->GetHealth() - dmg;
}