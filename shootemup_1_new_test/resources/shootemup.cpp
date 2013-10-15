#include "shootemup.h"

void initMenu()
{
	//bgMenu = CreateSprite( "./images/menu.jpg", SCREEN_X, SCREEN_Y, true );
	//MoveSprite(bgMenu, SCREEN_X>>1, SCREEN_Y>>1);
}

void updateMenu()
{
	DrawString("Menu", 1000, 50, SColour(0,255,0,255));
}

void drawMenu()
{
	//DrawSprite(bgMenu);
	DrawString("Menu", 1000, 50, SColour(0,255,0,255));
}

void menuState()
{
	initMenu();
	updateMenu();
	drawMenu();
}