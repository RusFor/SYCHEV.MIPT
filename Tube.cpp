#include "Tube.h"
#include "Bird.h"
#include <stdlib.h>

int Tube::checkCollision(Bird& bird)
{
	if (bird.getX() + birdHead > pos.x && bird.getX() < pos.x + size.x &&
		(bird.getY() + birdHighWing < pos.y || bird.getY() + birdLowWing > pos.y + size.y))
		bird.changeV();
	if (!passed && bird.getX() > pos.x + size.x)
	{
		passed = true;
		return 100;
	}
	return 0;
}

void Tube::move(double dt)
{
	pos.x += vel.x * dt;

}

bool Tube::isOut()
{
	return pos.x + size.x < 0;
}

int Tube::getX()
{
	return int(pos.x);
}

int Tube::getY()
{
	return int(pos.y);
}

int  Tube::getW()
{
	return int(size.x);
}

int  Tube::getH()
{
	return int(size.y);
}