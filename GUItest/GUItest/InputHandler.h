#pragma once
#include <SDL.h>
#include <stdio.h>
#include <string.h>

#include "ScreenManager.h"

class InputHandler {

public:
	enum MOUSE_BUTTON { left = 0, right, middle, back, forward };

	//Holds the mouse button state of the last frame (used to catch mouse button press and release events)
	Uint32 mPrevMouseState;
	//Holds the mouse button state of the current frame
	Uint32 mMouseState;

	//Used to retrieve the current mouse position using SDL_GetMouseState
	int mMouseXPos;
	int mMouseYPos;

	static InputHandler* Instance();
	static void Release();

	void Update();

	//------------------------------------------------------------
	//Returns true as long as the given mouse button is held down 
	//------------------------------------------------------------
	bool MouseButtonDown(MOUSE_BUTTON botton);
	//----------------------------------------------------------------------
	//Returns true only on the frame that the given mouse button is pressed 
	//----------------------------------------------------------------------
	bool MouseButtonPressed(MOUSE_BUTTON button);
	//-----------------------------------------------------------------------
	//Returns true only on the frame that the given mouse button is released 
	//-----------------------------------------------------------------------
	bool MouseButtonReleased(MOUSE_BUTTON button);

	//------------------------------------------------------------------
	//Returns a Vector2 containing the current mouse position on screen 
	//------------------------------------------------------------------
	int MouseXPos();
	int MouseYPos();

	//-------------------------------------------------------------------------------------------------
		//Sets the current frame's key states as the previous key states (to be called in the LateUpdate)  
		//No input checks should be made in the current frame after this function is called                
		//-------------------------------------------------------------------------------------------------
	void UpdatePrevInput();

private:
	InputHandler();
	~InputHandler();

	static InputHandler* sInstance;

	ScreenManager* sScreenManager;
};