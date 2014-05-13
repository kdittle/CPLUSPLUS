/*

GameEntity is a base class for all loaded and rendered objects

*/

#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include "Headers.h"
#include "Vector2f.h"

//Set up the window, renderer, and screen
//Shouldn't be global, but works for now
static SDL_Window* mWindow;
static SDL_Renderer* mRenderer;
static SDL_Surface* mScreen;

class GameEntity
{
public:
	SDL_Texture* mTexture;						//texture for loading
	Vector2f<float> Location;					//location for entities

	//These should be private
	SDL_Rect m_BoundingBox;						//bounding boxes for collision
	std::vector<SDL_Rect> m_ColliderBoxes;		//Colliders for collision

	GameEntity();	//Constuctor
	~GameEntity();	//Deconstructor

	void InitializeSDL();			//Initializes SDL
	SDL_Renderer* GetRenderer();	//Returns renderer

	void Destory();					//Destorys the entity and frees it
	void Update(float deltaTime);

	void free();					//Frees entity.
	bool LoadFromFile(const std::string filePath);	//Loads files

	//Render textures
	void Render(Vector2f<float> position, SDL_Rect* clip = NULL, float angle = 0.0f, SDL_Point* center = NULL,
		SDL_RendererFlip = SDL_FLIP_NONE);

	int getWidth();
	int getHeight();

	//Getbounding box and get colliders
	SDL_Rect GetBoundingBox();
	std::vector<SDL_Rect>& GetColliderBoxes();

	//Shifts boxes and colliders for collision
	void shiftBoundingBox();
	void shiftColliderBoxes();

	int GetWindowHeight();
	int GetWindowWidth();

private:
	//Texture width and height
	int mWidth;
	int mHeight;

protected:
	const int WINDOW_WIDTH = 720;
	const int WINDOW_HEIGHT = 680;

};

#endif