#pragma once

#include <iostream>
#include <string>
#include "TitleScreen.h"
#include "PlayScreen.h"
//#include "Instructions.h"
//#include "Scores.h"

class ScreenManager {


public:

	static ScreenManager* Instance();
	static void Release();

	void Switch();
	void Update();
	void Render();
	void Events(int x, int y);

	//SCREENS convert(const std::string& str);

private:
	ScreenManager();
	~ScreenManager();

	enum SCREENS { start, play, scores, instructions };

	static ScreenManager* sInstance;
	
	TitleScreen* sTitleScreen;
	PlayScreen* sPlayScreen;
	// Scores* sScores;
	// Instructions* sInstructions;

	SCREENS currentScreen;
};