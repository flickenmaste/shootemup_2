// By: Will Gilstrap
// Last edit: 10/9/2013
// Shoot em up game
//////////////////////////////////////////////////////////////////////////
#define _USE_MATH_DEFINES

#include "AIE.h"
//#include "KeyCodes.h"
#include <string>
#include <cmath>
#include <assert.h>
#include <crtdbg.h>
#include <ctime>
#include <iostream>
#include <vector>
#include "shootemup.h"


bool checkCollision(movableObject& obj1, bullets& obj2) {
	int x; int y;
	GetMouseLocation(x,y);
	if (obj1.position.x - 25 < obj2.position.x && obj1.position.x + 25 > obj2.position.x &&
			obj1.position.y + 25 > obj2.position.x &&
			obj1.position.y - 25 < obj2.position.x)
		return true;
	else
		return false;
}

void seek(movableObject &player, movableObject& ball)
{
	float speed = 0;

	if(player.position.y < ball.position.y - speed) {
		int diff = ball.position.y - player.position.y;
		if(diff > speed)
			player.position.y += speed;
		else
			player.position.y += diff;
	}
	else if (player.position.y > ball.position.y + speed) {
		int diff = player.position.y - ball.position.y;
		if(diff > speed)
			player.position.y -= speed;
		else
			player.position.y -= diff;
	}
}

void movePlayer(movableObject& obj)	// function to make the player sprite follow mouse
{
	int x; int y;
	GetMouseLocation(x,y);
	obj.position.x = x;
	obj.position.y = y;
	movableObject mouse = {x, y, 0, 0, -1 , 50, 50};
	seek(player1, mouse);
	MoveSprite(player1.sprite, player1.position.x, player1.position.y);
	return;
}

void playerShoot(bullets& obj, bullets& obj2, bullets& obj3)	// function to test if player is shooting or not
{
	// bullet 1
	int x; int y;
	GetMouseLocation(x,y);
	if (obj.position.y < 0)
	obj.dead = true;
	else
		obj.dead = false;
	if (obj.position.y < 0)
	obj.dead = true;
	else
		obj.dead = false;
	if (GetMouseButtonDown(MOUSE_BUTTON_1) == true)
	obj.alive = true;
	

	// bullet 2
	if (obj2.position.y < 0 || obj2.position.x < 0)
	obj2.dead = true;
	else
		obj2.dead = false;
	if (obj2.position.y < 0 || obj2.position.x < 0)
	obj2.dead = true;
	else
		obj2.dead = false;
	if (GetMouseButtonDown(MOUSE_BUTTON_1) == true)
	obj2.alive = true;
	

	//bullet 3
	if (obj3.position.y < 0)
	obj3.dead = true;
	else
		obj3.dead = false;
	if (obj3.position.y < 0)
	obj3.dead = true;
	else
		obj3.dead = false;
	if (GetMouseButtonDown(MOUSE_BUTTON_1) == true)
	obj3.alive = true;
	

	return;
}

void ifAlive(bullets& obj, bullets& obj2, bullets& obj3)	// function executed if player is shooting
{
	//bullet 1
	obj.position.y -= obj.speed.y;
	//bullet 2
	obj2.position.x -= 1;
	obj2.position.y -= obj2.speed.y;
	//bullet 3
	obj3.position.x += 1;
	obj3.position.y -= obj3.speed.y;

}

void ifDead(bullets& obj, bullets& obj2, bullets& obj3)	// executed if bullets leave screen
{
	if (GetMouseButtonDown(MOUSE_BUTTON_1) == true) {
	// bullet 1
	int x; int y;
	GetMouseLocation(x,y);
	if (obj.position.y < 0)
	obj.position.x = x;
	if (obj.position.y < 0)
	obj.position.y = y;

	// bullet 2
	if (obj2.position.y < 0 || obj2.position.x < 0)
	obj2.position.x = x;
	if (obj2.position.y < 0 || obj2.position.x < 0)
	obj2.position.y = y;

	//bullet 3
	if (obj3.position.y < 0)
	obj3.position.x = x;
	if (obj3.position.y < 0)
	obj3.position.y = y;

	playerBullet.alive = false; playerBullet2.alive = false; playerBullet3.alive = false;
	}
}

void spawnEnemy(movableObject& obj)	// function to spawn a basic enemy
{
	int spawn = rand() % SCREEN_X;
	if (obj.position.y > SCREEN_Y)
	obj.position.x = spawn;
	if (obj.position.y > SCREEN_Y)
	obj.position.y = 0;
	else
	obj.position.y += obj.speed.y;
}

// check if one object has collided with another object
// returns true if the two objects have collided
bool checkCollision(movableObject& obj1) {	
	int x; int y;
	GetMouseLocation(x,y);
	if (GetMouseButtonDown(MOUSE_BUTTON_1) == true && obj1.position.x - obj1.width < x && obj1.position.x + obj1.width > x &&
			obj1.position.y > y - obj1.height &&
			obj1.position.y < y + obj1.height)
		return true;
	else
		return false;
}

// initialize all the variables in the game
void initGame() {
	srand(time(0));

	// Now load some sprites
	bgImage = CreateSprite( "./images/bg.jpg", SCREEN_X, SCREEN_Y, true );
	MoveSprite(bgImage, SCREEN_X>>1, SCREEN_Y>>1);

	player1.sprite = CreateSprite( "./images/player.png", PLAYER1_W, PLAYER1_H, true );
	playerBullet.sprite = CreateSprite( "./images/bullet.png", 10, 10, true );
	playerBullet2.sprite = CreateSprite( "./images/bullet.png", 10, 10, true );
	playerBullet3.sprite = CreateSprite( "./images/bullet.png", 10, 10, true );
	enemy.sprite = CreateSprite( "./images/enemy.png", 50, 50, true );
	
}

// destroy all the sprites and clean up any memory
void destroyGame() {
	DestroySprite(bgImage);
	DestroySprite(player1.sprite);
	DestroySprite(playerBullet.sprite);
	DestroySprite(playerBullet2.sprite);
	DestroySprite(playerBullet3.sprite);
	DestroySprite(enemy.sprite);
}

// update the game logic here
void updateGame() {
	//playerBullet.alive = false; playerBullet2.alive = false; playerBullet3.alive = false; 
	movePlayer(player1);
	playerShoot(playerBullet, playerBullet2, playerBullet3);
	spawnEnemy(enemy);
	if (playerBullet.alive == true && playerBullet2.alive == true && playerBullet3.alive == true)
		ifAlive(playerBullet, playerBullet2, playerBullet3);


	if (playerBullet.dead == true && playerBullet2.dead == true && playerBullet3.dead == true)
	ifDead(playerBullet, playerBullet2, playerBullet3);

	if (checkCollision(enemy, playerBullet) == true || checkCollision(enemy, playerBullet2) == true || checkCollision(enemy, playerBullet3) == true)
	{
		std::cout << "It's working." << std::endl;
	}


	RotateSprite(player1.sprite, 0);
	MoveSprite(player1.sprite, player1.position.x, player1.position.y);
	
	RotateSprite(playerBullet.sprite, 0);
	MoveSprite(playerBullet.sprite, playerBullet.position.x, playerBullet.position.y);
	RotateSprite(playerBullet2.sprite, 0);
	MoveSprite(playerBullet2.sprite, playerBullet2.position.x, playerBullet2.position.y);
	RotateSprite(playerBullet3.sprite, 0);
	MoveSprite(playerBullet3.sprite, playerBullet3.position.x, playerBullet3.position.y);

	RotateSprite(enemy.sprite, 0);
	MoveSprite(enemy.sprite, enemy.position.x, enemy.position.y);
	
	gameProcess = &drawGame;
	//playerBullet.alive = false; playerBullet2.alive = false; playerBullet3.alive = false; 
}

// draws each frame of the game
void drawGame() {
	
	DrawSprite(bgImage);
	DrawSprite(playerBullet.sprite);
	DrawSprite(playerBullet2.sprite);
	DrawSprite(playerBullet3.sprite);
	DrawSprite(player1.sprite);
	DrawSprite(enemy.sprite);

}

// entry point of the program
int main( int arc, char* argv[] )
{	
	// First we need to create our Game Framework
	Initialise(SCREEN_X, SCREEN_Y, false );

	initGame();
	gameProcess = &updateGame;	
	do {
		frameCounter++;

		if(frameCounter > 5000)
			frameCounter = 0;

		ClearScreen();
		
		//gameProcess();
		updateGame();

		drawGame();
	} while ( FrameworkUpdate() == false );

	destroyGame();
	
	Shutdown();

	return 0;
}

