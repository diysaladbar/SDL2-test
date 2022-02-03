#pragma once
#include <string>
#include "GameEntity.h"
#include "Texture.h"

class TitleScreen: public GameEntity {
public:

	TitleScreen();
	~TitleScreen();


	void Update();
	void Render();
	std::string Events(int x, int y);

private:

	//title
	GameEntity* title;
	Texture* name;

	GameEntity* buttons;
	Texture* startGame;
	Texture* showScores;
	Texture* instructions;
	Texture* exitGame;

};