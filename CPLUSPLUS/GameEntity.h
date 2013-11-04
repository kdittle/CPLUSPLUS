#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include "OpenGLHeaders.h"
#include "Vector2f.h"

class GameEntity
{
public:
	Vector2f Location;
	Vector2f X_Velocity;
	Vector2f Y_Velocity;

	GameEntity();
	~GameEntity();

	void Destory();
	void Update();
	void Draw(SDL_Window* tragetWindow);

	void LoadImageFromFile(std::string& filePath);

};

#endif