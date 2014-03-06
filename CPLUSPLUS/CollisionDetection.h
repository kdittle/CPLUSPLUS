#ifndef COLLISIONDETECTION_H
#define COLLISIONDETECTION_H

#include "Headers.h"

class CollisionDetection
{
public:
	//Collision for simple rectangle bounding boxes
	bool Check_Box_Collision(SDL_Rect a, SDL_Rect b);

	//Per pixel
	//Doesn't work yet, should work on this eventually.
	bool Per_Pixel_Collision(std::vector<SDL_Rect>& a, std::vector<SDL_Rect>& b);

};

#endif