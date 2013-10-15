#include "shootemup.h"


unsigned int bgMenu = -1;
unsigned int bgGameOver = -1;

void initMenu()
{
	bgMenu = CreateSprite( "./images/menu3.jpg", SCREEN_X, SCREEN_Y, true );
	MoveSprite(bgMenu, SCREEN_X>>1, SCREEN_Y>>1);
}

void updateMenu()
{
	if (IsKeyDown(32) == true)
		gameProcess = &playState;
	//if (GetMouseButtonDown(MOUSE_BUTTON_1) == true && checkMouseClick(playGame) == true)
		//gameProcess = &playState;
}

void drawMenu()
{
	//DrawSprite(bgMenu);
	DrawString("Menu", SCREEN_X / 2, SCREEN_Y / 2, SColour(0,0xFF,0,0));
	DrawString("Press SPACE to play...", SCREEN_X / 2 - 100, SCREEN_Y / 2 + 50, SColour(0,255,255,255));
	//DrawString("Exit", SCREEN_X / 2, SCREEN_Y / 2 + 100, SColour(255,4,45,255));
	DrawString("Controls: LEFT MOUSE to shoot", 870, 750, SColour(0,255,0,255));
	DrawSprite(bgMenu);
}

void destroyMenu()
{
	DestroySprite(bgMenu);
}

void menuState()
{
	ClearScreen();
	updateMenu();
	drawMenu();
}

void playState()
{
	ClearScreen();
	updateGame();
	drawGame();
}

void initGameOver()
{
	bgGameOver = CreateSprite( "./images/gameover.jpg", SCREEN_X, SCREEN_Y, true );
	MoveSprite(bgGameOver, SCREEN_X>>1, SCREEN_Y>>1);
}

void updateGameOver()
{
	if (IsKeyDown(KEY_SPECIAL+38) == true)
		gameProcess = &menuState;
	//if (GetMouseButtonDown(MOUSE_BUTTON_1) == true && checkMouseClick(playGame) == true)
		//gameProcess = &playState;
}

void drawGameOver()
{
	//DrawSprite(bgMenu);
	DrawString("Game over", SCREEN_X / 2, SCREEN_Y / 2, SColour(0,0xFF,0,0));
	DrawSprite(bgGameOver);
}

void destroyGameOver()
{
	DestroySprite(bgGameOver);
}

void gameOverState()
{
	ClearScreen();
	updateGameOver();
	drawGameOver();
	resetEnemy(enemy);
	resetEnemy(enemy2);
	scores = 0;
}