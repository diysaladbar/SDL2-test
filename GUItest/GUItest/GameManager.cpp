#include "GameManager.h"

GameManager* GameManager::sInstance = NULL;

GameManager* GameManager::Instance() {

	//Create a new instance if no instance was created before
	if(sInstance == NULL)
		sInstance = new GameManager();

	return sInstance;
}

void GameManager::Release() {

	delete sInstance;
	sInstance = NULL;
}

GameManager::GameManager() {

	mQuit = false;

	//Initialize SDL
	mGraphics = Graphics::Instance();

	// Quits the game if SDL fails to initialize
	if(!Graphics::Initialized())
		mQuit = true;

	//Initialize AssetManager
	mAssetMgr = AssetManager::Instance();

	//Initialize InputHandler
	mInputHdl = InputHandler::Instance();

	//Initialize ScreenManager
	sScreenMgr = ScreenManager::Instance();
}

GameManager::~GameManager() {

	ScreenManager::Release();
	sScreenMgr = NULL;

	AssetManager::Release();
	mAssetMgr = NULL;

	Graphics::Release();
	mGraphics = NULL;

	InputHandler::Release();
	mInputHdl = NULL;
}

void GameManager::EarlyUpdate() {

	//Updating the input state before any other updates are run to make sure the Input check is accurate
	mInputHdl->Update();
}

void GameManager::Update() {

	//GameEntity Updates should happen here
	sScreenMgr->Update();
}

void GameManager::LateUpdate() {

	//Any collision detection should happen here
	mInputHdl->UpdatePrevInput();
}

void GameManager::Render() {

	//Clears the last frame's render from the back buffer
	mGraphics->ClearBackBuffer();

	//All other rendering is to happen here
	sScreenMgr->Render();

	//Renders the current frame
	mGraphics->Render();
}

void GameManager::Run() {

	while(!mQuit) {

		while(SDL_PollEvent(&mEvents) != 0) {
			//Checks if the user quit the game
			if(mEvents.type == SDL_QUIT) {

				mQuit = true;
			}
		}

		EarlyUpdate();
		Update();
		LateUpdate();
		Render();

	}
}