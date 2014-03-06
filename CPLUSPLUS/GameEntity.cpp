#include "GameEntity.h"

//Constructor for GameEntities
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

//Destory the entity
GameEntity::~GameEntity()
{
	free();
	SDL_DestroyTexture(mTexture);
	mWidth = 0;
	mHeight = 0;
}

//Initialize SDL
void GameEntity::InitializeSDL()
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	//Create Window
	mWindow = SDL_CreateWindow("CPLUSPLUS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	if (mWindow == NULL)
	{
		printf("Unable to create window %s! SDL_Window Error: %s\n", SDL_GetError());
	}

	//Create renderer
	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);

	if (mRenderer == NULL)
	{
		printf("Unable to create renderer %s! SDL_Renderer Error: %s\n", SDL_GetError());
	}

	//Create screen
	mScreen = SDL_GetWindowSurface(mWindow);

	if (mScreen == NULL)
	{
		printf("Unable to create screen %s! SDL_Surface Error: %s\n", SDL_GetError());
	}
}

SDL_Renderer* GameEntity::GetRenderer()
{
	return mRenderer;
}

//Free texture
void GameEntity::Destory()
{
	SDL_DestroyTexture(mTexture);
}

void GameEntity::Update(float deltaTime)
{
	
}

//Free texture and reset it all to defaults
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

//Load
bool GameEntity::LoadFromFile(const std::string filePath)
{
	//Free mTexture to be reused
	free();

	//Temporary texture
	SDL_Texture* newTexture = NULL;

	//Load image to surface
	SDL_Surface* loadedSurface = IMG_Load(filePath.c_str());
	if(loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", filePath.c_str(), SDL_GetError());
	}
	else
	{
		//Set the color key for the loaded surface and format
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0xFF, 0xFF, 0xFF));

		//Create texture from the loaded surface
		newTexture = SDL_CreateTextureFromSurface(mRenderer, loadedSurface);
		if(newTexture == NULL)
		{
			printf("Unable to create textrue from %s! SDL_Error %s\n", filePath.c_str(), SDL_GetError());
		}
		else
		{
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Free the surface as it is no longer needed
		SDL_FreeSurface(loadedSurface);
	}

	//mTexutre becomes the loaded texture
	mTexture = newTexture;

	return mTexture != NULL;
}

//Render the textures
void GameEntity::Render(Vector2f<float> position, SDL_Rect* clip, float angle, SDL_Point* center,
						SDL_RendererFlip flip)
{
	SDL_Rect renderQuad = {position._x, position._y, mWidth, mHeight};

	if(clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	SDL_RenderCopyEx(mRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}

int GameEntity::getHeight()
{
	return mHeight;
}

int GameEntity::getWidth()
{
	return mWidth;
}

//Shift boxes for collision
void GameEntity::shiftBoundingBox()
{
	m_BoundingBox.x = Location._x;
	m_BoundingBox.y = Location._y;
}

SDL_Rect GameEntity::GetBoundingBox()
{
	return m_BoundingBox;
}

//Shift boxes for collision
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
