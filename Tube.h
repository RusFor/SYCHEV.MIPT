#pragma once
#include "Structs.h"
#include "Bird.h"

const int tubeSpeed = -150;

class Tube
{
	Vector2d pos;
	Vector2d size;
	Vector2d vel;
	bool passed = false;

public:
	Tube(double posX, double posY, double velX, double velY, double sizeX, double sizeY) :
		pos(Vector2d(posX, posY)), vel(Vector2d(velX, velY)), size(Vector2d(sizeX, sizeY)) {}

	int checkCollision(Bird& bird);

	void move(double dt);

	bool isOut();

	int getX();

	int getY();

	int getW();

	int getH();

};
