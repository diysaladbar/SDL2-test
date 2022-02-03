#include "ScreenManager.h"


ScreenManager* ScreenManager::sInstance = NULL;

ScreenManager* ScreenManager::Instance() {
	if (sInstance == NULL) {
		sInstance = new ScreenManager();
	}

	return sInstance;
}

void ScreenManager::Release() {
	delete sInstance;
	sInstance = NULL;
}

ScreenManager::ScreenManager() {
	
	//mInput = InputManager::Instance();

	sTitleScreen = new TitleScreen();
	sPlayScreen = new PlayScreen();
	// sInstructions = new instructions();
	// sScores = new Scores();

	currentScreen = play;
}

ScreenManager::~ScreenManager() {

	//mInput = NULL;
	delete sTitleScreen;
	sTitleScreen = NULL;
	delete sPlayScreen;
	sPlayScreen = NULL;
}
	

void ScreenManager::Update() {
	switch (currentScreen) {
	case start:
		sTitleScreen->Update();
		break;

	case play:
		sPlayScreen->Update();
		break;

		/*case scores:
			sScores->Update();
			break;
		}

		case instructions:
			sInstructions->Update();
			break; */
	}
}




void ScreenManager::Render() {
	switch (currentScreen) {
	case start:
		sTitleScreen->Render();
		break;

	case play:
		sPlayScreen->Render();
		break;

	/*case scores:
		sScores->Render();
		break;*/

	/*case instructions
		sInstructions->Render();
		break;*/
	}
}

/* used to test switching, not necessary for full implementation
void ScreenManager::Switch() {
	switch (currentScreen) {
	case start:
		currentScreen = play;
		break;

	case play:
		currentScreen = start;
		break;
	}
}
*/

void ScreenManager::Events(int x, int y) {
	// basically add a case for each screen in the SCREENS enum
	// add more if statement clauses depending on which button in being pressed
	// they should do different things.
	// each screen class should have their own Events() function to handle their own buttons
	// a known problem with these screen specific Events() functions is that they use && comparisons and inequalities to find
	// where the button is which basically creates a NxM region where the press returns a button specific string
	// the problem is that these regions are aligned at (0, 0) and not where the button actually is
	// another known issue is that holding down the mouse click means that the screens will constantly switch back and forth.
	switch (currentScreen) {
	case start:
		if (sTitleScreen->Events(x, y) == "play") {
			currentScreen = play;
		}
		break;

	case play:
		if (sPlayScreen->Events(x, y) == "start") {
			currentScreen = start;
		}
		break;
	}
}