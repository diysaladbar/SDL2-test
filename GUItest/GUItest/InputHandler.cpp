#include "InputHandler.h"


InputHandler* InputHandler::sInstance = NULL;

InputHandler* InputHandler ::Instance() {
	if (sInstance == NULL) {
		sInstance = new InputHandler();
	}

	return sInstance;
}

void InputHandler::Release() {
	delete sInstance;
	sInstance = NULL;
}

InputHandler::InputHandler() {
	sScreenManager = ScreenManager::Instance();
}

InputHandler::~InputHandler() {
	ScreenManager::Release();
	sScreenManager = NULL;
}

int InputHandler::MouseXPos() {
	return mMouseXPos;
}

int InputHandler::MouseYPos() {
	return mMouseYPos;
}

bool InputHandler::MouseButtonDown(MOUSE_BUTTON button) {

	//mask to be using for bit wise operations
	Uint32 mask = 0;

	switch (button) {

	case left:

		mask = SDL_BUTTON_LMASK;
		break;

	case right:

		mask = SDL_BUTTON_RMASK;
		break;

	case middle:

		mask = SDL_BUTTON_MMASK;
		break;

	case back:

		mask = SDL_BUTTON_X1MASK;
		break;

	case forward:

		mask = SDL_BUTTON_X2MASK;
		break;
	}

	//return true if the mask exists in the current mouse state
	return ((mMouseState & mask) != 0);
}

bool InputHandler::MouseButtonPressed(MOUSE_BUTTON button) {

	//mask to be using for bit wise operations
	Uint32 mask = 0;

	switch (button) {

	case left:

		mask = SDL_BUTTON_LMASK;
		break;

	case right:

		mask = SDL_BUTTON_RMASK;
		break;

	case middle:

		mask = SDL_BUTTON_MMASK;
		break;

	case back:

		mask = SDL_BUTTON_X1MASK;
		break;

	case forward:

		mask = SDL_BUTTON_X2MASK;
		break;
	}

	//return true if the mask does not exist in the previous mouse state, but exists in the current one
	return ((mPrevMouseState & mask) == 0) && ((mMouseState & mask) != 0);
}

bool InputHandler::MouseButtonReleased(MOUSE_BUTTON button) {

	Uint32 mask = 0;

	switch (button) {

	case left:

		mask = SDL_BUTTON_LMASK;
		break;

	case right:

		mask = SDL_BUTTON_RMASK;
		break;

	case middle:

		mask = SDL_BUTTON_MMASK;
		break;

	case back:

		mask = SDL_BUTTON_X1MASK;
		break;

	case forward:

		mask = SDL_BUTTON_X2MASK;
		break;
	}

	//return true if the mask exists in the previous mouse state, but does not exist in the current one
	return ((mPrevMouseState & mask) != 0) && ((mMouseState & mask) == 0);
}

void InputHandler::Update() {

	//Updating the mouse state to get the key states of the current frame
	mMouseState = SDL_GetMouseState(&mMouseXPos, &mMouseYPos);
	if (MouseButtonDown(left)) {
		printf("left, %d %d\n", mMouseXPos, mMouseYPos);
		sScreenManager->Events(mMouseXPos, mMouseYPos);
	}
	
}

void InputHandler::UpdatePrevInput() {
	//Setting the previous mouse state as the current mouse state at the end of the frame
	mPrevMouseState = mMouseState;
}