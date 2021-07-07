#include "Apples.h"
#include "Bird.h"
#include <stdlib.h>

int Apple::checkCollision(Bird& bird)
{
	if ((bird.getX() + birdHead > pos.x && bird.getX() < pos.x + size.x) &&
		(bird.getY() + birdLowWing > pos.y && bird.getY() + birdHighWing < pos.y + size.y))
		if (!took)
		{
			took = true;
			return 50;
		}
	return 0;
}

void Apple::move(double dt)
{
	pos.x += vel.x * dt;

}

bool Apple::isOut()
{
	return pos.x + size.x < 0 || took;
}

int Apple::getX()
{
	return int(pos.x);
}

int Apple::getY()
{
	return int(pos.y);
}

int  Apple::getW()
{
	return int(size.x);
}

int  Apple::getH()
{
	return int(size.y);
}