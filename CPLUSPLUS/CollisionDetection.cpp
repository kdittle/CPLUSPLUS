#include "CollisionDetection.h"

bool CollisionDetection::Check_Box_Collision(SDL_Rect a, SDL_Rect b)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	if(bottomA <= topB)
	{
		return false;
	}

	if(topA >= bottomB)
	{
		return false;
	}

	if(rightA <= leftB)
	{
		return false;
	}

	if(leftA >= rightB)
	{
		return false;
	}

	return true;
}

bool CollisionDetection::Per_Pixel_Collision(std::vector<SDL_Rect>& a, std::vector<SDL_Rect>& b)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	for (int boxA = 0; boxA < a.size(); boxA++)
	{

		leftA = a[boxA].x;
		rightA = a[boxA].x + a[boxA].w;
		topA = a[boxA].y;
		bottomA = a[boxA].y + a[boxA].h;


		for (int boxB = 0; boxB < b.size(); boxB++)
		{
			leftB = b[boxB].x;
			rightB = b[boxB].x + b[boxB].w;
			topB = b[boxB].y;
			bottomB = b[boxB].y + b[boxB].h;


			if (((bottomA <= topB) || (topA >= bottomB) || (rightA <= leftB) || (leftA >= rightB)) == false)
			{
				return true;
			}
		}
	}

	return false;
}