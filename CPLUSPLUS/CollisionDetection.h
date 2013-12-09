#ifndef COLLISIONDETECTION_H
#define COLLISIONDETECTION_H

#include "Headers.h"

class CollisionDetection
{
public:

	bool Check_Box_Collision(SDL_Rect a, SDL_Rect b);
	bool Per_Pixel_Collision(std::vector<SDL_Rect>& a, std::vector<SDL_Rect>& b);

};

#endif