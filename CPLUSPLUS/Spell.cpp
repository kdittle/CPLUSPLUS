#include "Spell.h"

/*

This spell class is set up for the fire shield spell
It will have to be modified to be used for projectiles

*/

//Set defaults for the spells
Spell::Spell()
{

}

//Update the spell
void Spell::Update(float deltaTime)
{
	Base::Update(deltaTime);
}

//Set up the bounding box for the spell
void Spell::SetBoundingBox(Vector2f<float> position)
{
	m_BoundingBox.x = position._x;
	m_BoundingBox.y = position._y ;
	m_BoundingBox.w = getWidth() / 2.0f;
	m_BoundingBox.h = getHeight();
}

//Check collision for the spell.
bool Spell::checkCollision(SDL_Rect player, SDL_Rect enemy)
{
	if (collisionHandler.Check_Box_Collision(player, enemy))
	{
		return true;
	}

	return false;
}