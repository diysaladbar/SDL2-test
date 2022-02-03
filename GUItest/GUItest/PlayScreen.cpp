#include "PlayScreen.h"
//using namespace std;


PlayScreen::PlayScreen() {
    
    //title
    title = new GameEntity(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.90f);
    SDL_Color textColor = { 0, 0, 0, 0xFF };
    name = new Texture("Play", "lazy.ttf", 76, textColor);

    name->setParent(title);
    name->setPos(Graphics::Instance()->SCREEN_WIDTH * 0.5f, 100);

    title->setParent(this);
    title->setPos(100, 100);

    //buttons
    buttons = new GameEntity(1000.0, 1000.0);
    //
    quit = new Texture("button.png", 0, 0, 300, 100);
    quit->setParent(title);
    quit->setPos(Graphics::Instance()->SCREEN_WIDTH * 0.5f, 300);
    /*blocks = new GameEntity(1000.0, 1000.0);
    board = new GameEntity(1000.0, 1000.0);
    
    //im not sure about the x and y values
    restart = new Texture("RESTART.png", 1000, 660, 200, 100);
    quit = new Texture("QUIT.png", 1000, 60, 200, 100);
    gameBoard = new Texture("GameBoard.png", 340, 60, 600, 600);
    mainBlock = new Texture("BOY.png", 440, 360, 200, 100);
    tiger = new Texture("TIGER.png", 640, 160, 300, 100);
    pig = new Texture("PIG.png", 540, 560, 200, 100);
    panda = new Texture("panda.png", 740, 360, 200, 300);
    fox = new Texture("FOX.png", 440, 60, 100, 200);
    zebra = new Texture("ZEBRA.png", 640, 360, 100, 200);

    restart->setParent(buttons);
    restart->setPos(1000, 660);
    quit->setParent(buttons);
    quit->setPos(1000, 60);
    
    gameBoard->setParent(board);
    gameBoard->setPos(340, 60);
    
    mainBlock->setParent(blocks);
    mainBlock->setPos(440, 360);
    tiger->setParent(blocks);
    tiger->setPos(640, 160);
    pig->setParent(blocks);
    pig->setPos(540, 560);
    panda->setParent(blocks);
    panda->setPos(740, 360);
    fox->setParent(blocks);
    fox->setPos(440, 60);
    zebra->setParent(blocks);
    zebra->setPos(640, 360);
    
    blocks->setParent(this);
    board->setParent(this);
    buttons->setParent(this);
    */
}

PlayScreen::~PlayScreen() {
    //titles
    delete title;
    title = NULL;
    delete name;
    name = NULL;
    delete buttons;
    buttons = NULL;
    delete quit;
    quit = NULL;

    /*
    //gameEntities
    delete board;
    board = NULL;
    delete blocks;
    blocks = NULL;
    
    //blocks
    delete mainBlock;
    mainBlock = NULL;
    delete tiger;
    tiger = NULL;
    delete pig;
    pig = NULL;
    delete panda;
    panda = NULL;
    delete fox;
    fox = NULL;
    delete zebra;
    zebra = NULL;
   

    //buttons
    delete buttons;
    buttons = NULL;
    delete restart;
    restart = NULL;
    delete quit;
    quit = NULL;
    */
}

void PlayScreen::Update() {
    name->Update();
}
void PlayScreen::Render() {
    //restart->Render();
    quit->Render();
}

std::string PlayScreen::Events(int x, int y) {
    // general form is, for each button, check if x and y is within the region that the button occupies
    // add a new if statment clause for each button and have it return a button specific string
    // the Events() function in ScreenManager should be updated to accomidate the returned strings
    // KNOWN ISSUE: valid regions are located at (0, 0) and not where the buttons actually are
    if (x > quit->getxPos() && y > quit->getyPos() && x < (quit->getxPos() + quit->buttonDim.w) && y < (quit->getxPos() + quit->buttonDim.h)) {
        return "start";
    } else {
        return "none";
    }
}
