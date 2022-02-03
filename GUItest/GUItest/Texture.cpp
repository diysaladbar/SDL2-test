#include "Texture.h"

Texture::Texture(std::string filename) {

	mGraphics = Graphics::Instance();

	//Loads the texture from the AssetManager to avoid loading textures more than once
	mTex = AssetManager::Instance()->GetTexture(filename);

	//Gets the Width and Height of the texture
	SDL_QueryTexture(mTex, NULL, NULL, &mWidth, &mHeight);

	//Clipped is false since the image is not loaded from a spritesheet
	mClipped = false;

	selected = false;

	mRenderRect.w = mWidth;
	mRenderRect.h = mHeight;

	buttonDim.x = 0;
	buttonDim.y = 0;
	buttonDim.w = mWidth;
	buttonDim.h = mHeight;
}

Texture::Texture(std::string filename, int x, int y, int w, int h) {

	mGraphics = Graphics::Instance();

	//Loads the texture from the AssetManager to avoid loading textures more than once
	mTex = AssetManager::Instance()->GetTexture(filename);

	//Clipped is true since the image could be loaded from a spritesheet
	mClipped = true;

	selected = false;

	mWidth = w;
	mHeight = h;

	mRenderRect.w = mWidth;
	mRenderRect.h = mHeight;

	//Setting the clipped rectangle to only get the needed texture from the spritesheet
	mClipRect.x = x;
	mClipRect.y = y;
	mClipRect.w = mWidth;
	mClipRect.h = mHeight;

	buttonDim.x = x;
	buttonDim.y = y;
	buttonDim.w = mWidth;
	buttonDim.h = mHeight;

}

Texture::Texture(std::string text, std::string fontPath, int size, SDL_Color color) {

	mGraphics = Graphics::Instance();

	//Loads the texture from the AssetManager to avoid loading textures more than once
	mTex = AssetManager::Instance()->GetText(text, fontPath, size, color);

	//Clipped is false since the image is not loaded from a spritesheet
	mClipped = false;

	selected = false;

	//Gets the Width and Height of the texture
	SDL_QueryTexture(mTex, NULL, NULL, &mWidth, &mHeight);

	mRenderRect.w = mWidth;
	mRenderRect.h = mHeight;
}

Texture::~Texture() {

	mTex = NULL;
	mGraphics = NULL;
	
}

void Texture::Render() {

	float xPos = getxPos(local);
	float yPos = getyPos(local);
	float xScale = getxScale(local);
	float yScale = getyScale(local);

	//Centers the texture on the texture's world position so that its position is not the top left corner
	mRenderRect.x = (int)(xPos - mWidth*0.5f);
	mRenderRect.y = (int)(yPos - mHeight*0.5f);

	//Scales the width and height according to the scale of the GameEntity
	mRenderRect.w = (int)(mWidth * xScale);
	mRenderRect.h = (int)(mHeight * yScale);

	mGraphics->DrawTexture(mTex, (mClipped) ? &mClipRect : NULL, &mRenderRect, getRotation(world));
}

