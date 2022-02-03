#include "TitleScreen.h"

TitleScreen::TitleScreen() {

	//title
	title = new GameEntity(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.90f);
	SDL_Color textColor = { 0, 0, 0, 0xFF };
	name = new Texture("Zoo Escape", "lazy.ttf", 76, textColor);

	name->setParent(title);
	name->setPos(Graphics::Instance()->SCREEN_WIDTH * 0.5f, 100);

	title->setParent(this);
	title->setPos(100, 100);
	//buttons
	buttons = new GameEntity(1000.0, 1000.0);
	startGame = new Texture("button.png", 0, 0, 300, 100);
	showScores = new Texture("button.png", 0, 0, 300, 100);
	instructions = new Texture("button.png", 0, 0, 300, 100);
	exitGame = new Texture("button.png", 0, 0, 300, 100);

	startGame->setParent(title);
	showScores->setParent(title);
	instructions->setParent(title);
	exitGame->setParent(title);

	startGame->setPos(Graphics::Instance()->SCREEN_WIDTH * 0.5f, 300);
	showScores->setPos(Graphics::Instance()->SCREEN_WIDTH * 0.5f, 400);
	instructions->setPos(Graphics::Instance()->SCREEN_WIDTH * 0.5f, 500);
	//exitGame->setPos(100, 100);
}

TitleScreen::~TitleScreen() {
	//titles
	delete title;
	title = NULL;
	delete name;
	name = NULL;

	//buttons
	delete buttons;
	buttons = NULL;
	delete startGame;
	startGame = NULL;
	delete showScores;
	showScores = NULL;
	delete instructions;
	instructions = NULL;
	delete exitGame;
	exitGame = NULL;
}

void TitleScreen::Update() {
	name->Update();

	//have to check which button is being updated
	// something something
	//	currentScreen = play;
	//	currentScreen = scores;

	// if exit button, exit
}

void TitleScreen::Render() {
	name->Render();
	startGame->Render();
	showScores->Render();
	instructions->Render();
	//exitGame->Render();
}

std::string TitleScreen::Events(int x, int y) {
	// general form is, for each button, check if x and y is within the region that the button occupies
	// add a new if statment clause for each button and have it return a button specific string
	// the Events() function in ScreenManager should be updated to accomidate the returned strings
	// KNOWN ISSUE: valid regions are located at (0, 0) and not where the buttons actually are
	if (x > startGame->getxPos() && y > startGame->getyPos() && x < (startGame->getxPos() + startGame->buttonDim.w) && y < (startGame->getxPos() + startGame->buttonDim.h)) {
		return "play";
	} else {
		return "none";
	}
}
