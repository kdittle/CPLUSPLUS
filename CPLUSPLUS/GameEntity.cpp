#include "GameEntity.h"

GameEntity::GameEntity()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;

	m_BoundingBox.x = Location._x;
	m_BoundingBox.y = Location._y;
	m_BoundingBox.w = mWidth;
	m_BoundingBox.h = mHeight;
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

void GameEntity::Render(Vector2f<float> position, SDL_Renderer* renderer, SDL_Rect* clip, float angle, SDL_Point* center,
						SDL_RendererFlip flip)
{
	SDL_Rect renderQuad = {position._x, position._y, mWidth, mHeight};

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
	m_BoundingBox.x = Location._x;
	m_BoundingBox.y = Location._y;
}

SDL_Rect GameEntity::GetBoundingBox()
{
	return m_BoundingBox;
}

void GameEntity::shiftColliderBoxes()
{
	int row = 0;

	for (int set = 0; set < m_ColliderBoxes.size(); set++)
	{
		m_ColliderBoxes[set].x = Location._x + (mWidth = m_ColliderBoxes[set].w) / 2;

		m_ColliderBoxes[set].y = Location._y + row;

		row += m_ColliderBoxes[set].h;
	}
}

std::vector<SDL_Rect>& GameEntity::GetColliderBoxes()
{
	return m_ColliderBoxes;
}
