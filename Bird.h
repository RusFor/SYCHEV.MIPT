#pragma once
#include "Structs.h"
#include "Engine.h"

//bird body
const int birdHead = 30;
const int birdHighWing = -10;
const int birdLowWing = 30;
const int birdSizeX = 20;
const int birdSizeY = 20;
const int birdHeadSizeX = 10;
const int birdHeadSizeY = 10;
const int birdWingSizeX = 10;
const int birdWingSizeY = 10;
//bird start
const int startPosX = SCREEN_WIDTH / 2;
const int startPosY = SCREEN_HEIGHT / 2;
const int birdSpeedX = 100;
const int birdSpeedY = 50;

class Bird
{
	const double gravity = 1;
	const double acceleration = 0.9;
	double timeFromWing = 0;
	double wingHight = -500;
	bool birdDead = false;
	Vector2d pos;
	Vector2d vel;


public:
	Bird(double posX, double posY, double velX, double velY) :
		pos(Vector2d(posX, posY)), vel(Vector2d(velX, velY)) {}

	void move(double dt);
	void wing();
	int getX();
	int getY();
	int getV();
	void changeV();
	bool isAlive();
	void reset();
};