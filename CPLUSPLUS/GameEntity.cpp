#include "GameEntity.h"

GameEntity::GameEntity()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;

	m_BoundingBox.w = mWidth / 2;
	m_BoundingBox.h = mHeight / 2;

	shiftBoundingBox();
}

GameEntity::~GameEntity()
{
	free();
	SDL_DestroyTexture(mTexture);
	mWidth = 0;
	mHeight = 0;
}

void GameEntity::Destory()
{
	SDL_DestroyTexture(mTexture);
}

void GameEntity::Update(float deltaTime)
{
	
}

void GameEntity::free()
{
	if(mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

bool GameEntity::LoadFromFile(const std::string filePath, SDL_Renderer* renderer)
{
	free();

	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(filePath.c_str());
	if(loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", filePath.c_str(), SDL_GetError());
	}
	else
	{
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0xFF, 0xFF, 0xFF));

		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if(newTexture == NULL)
		{
			printf("Unable to create textrue from %s! SDL_Error %s\n", filePath.c_str(), SDL_GetError());
		}
		else
		{
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		SDL_FreeSurface(loadedSurface);
	}

	mTexture = newTexture;

	return mTexture != NULL;
}

void GameEntity::Render(Vector2f position, SDL_Renderer* renderer, SDL_Rect* clip, float angle, SDL_Point* center,
						SDL_RendererFlip flip)
{
	SDL_Rect renderQuad = {position.x, position.y, mWidth, mHeight};

	if(clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	SDL_RenderCopyEx(renderer, mTexture, clip, &renderQuad, angle, center, flip);
}

int GameEntity::getHeight()
{
	return mHeight;
}

int GameEntity::getWidth()
{
	return mWidth;
}

void GameEntity::shiftBoundingBox()
{
	m_BoundingBox.x = Location.x + m_BoundingBox.w;
	m_BoundingBox.y = Location.y + m_BoundingBox.h;
}

SDL_Rect GameEntity::GetBoundingBox()
{
	return m_BoundingBox;
}
