#pragma once
#ifndef _SHOOTEMUP_H_
#define _SHOOTEMUP_H_

// By: Will Gilstrap
// Last edit: 10/14/2013
//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
//#include "KeyCodes.h"
#include <string>
#include <cmath>
#include <assert.h>
#include <crtdbg.h>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

struct vector2{
	float x;
	float y;
};

struct movableObject{
	vector2 position;
	vector2 speed;
	int sprite;
	int width;
	int height;
};

struct bullets{
	vector2 position;
	vector2 speed;
	int sprite;
	int width;
	int height;
	bool alive;
	bool dead;
};

const int SPEED = 10;
const int SCREEN_X = 1280;
const int SCREEN_Y = 780;

const int PLAYER1_X = 100;
const int PLAYER1_W = 100;
const int PLAYER1_H = 50;

void (*gameProcess)() = NULL;
//void updateGame();
void resetEnemy(movableObject& obj);
void updateGame();
void drawGame();
void initMenu();
void updateMenu();
void drawMenu();
void destroyMenu();
void initGameOver();
void updateGameOver();
void drawGameOver();
void destroyGameOver();

void menuState();
void playState();
void gameOverState();

//void drawMenu();

// global variables 
unsigned int bgImage = -1;
unsigned int bgMenu = -1;
unsigned int bgGameOver = -1;
movableObject player1 = {687, 386, 0, 0, -1 , 100, 50};
bullets playerBullet = {0, 790, 0, 4, -1 , 10, 10, false, true};
bullets playerBullet2 = {0, 790, -4, 4, -1 , 10, 10, false, true};
bullets playerBullet3 = {0, 790, -4, 4, -1 , 10, 10, false, true};
movableObject enemy = {-500, 800, 0, 1, -1 , 50, 50};
movableObject enemy2 = {-500, 800, 0, 1, -1 , 50, 50};
movableObject playGame = {SCREEN_X / 2, SCREEN_Y / 2 + 50, 0, 0, -1 , 100, 30};
movableObject exitMenu = {SCREEN_X / 2, SCREEN_Y / 2 + 100, 0, 0, -1 , 100, 30};
bool g_gameOver = false;
bool menuEnd = false;
unsigned int scores = 0;
vector<bullets> bulletLoaded;
//vector<bullets> bulletLoaded2;
//vector<bullets> bulletLoaded3;
int player1Score = 0;
int frameCounter = 0;

#endif