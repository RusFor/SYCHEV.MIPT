#include "Bird.h"

void Bird::move(double dt)
{
	timeFromWing += dt;
	pos.y += vel.y * dt;
	vel.y += gravity;

	if (pos.y + birdLowWing > SCREEN_HEIGHT || pos.y + birdHighWing < 0 || birdDead)
	{
		pos.y = startPosY;
		vel.y = 0;
		birdDead = true;
	}

}

void Bird::wing()
{
	if (timeFromWing > 0.3)
	{
		vel.y = wingHight;
		timeFromWing = 0;
	}
}

int Bird::getX()
{
	return int(pos.x);
}

int Bird::getY()
{
	return int(pos.y);
}

int Bird::getV()
{
	return int(vel.y);
}

void Bird::changeV()
{
	birdDead = true;
}

bool Bird::isAlive()
{
	return !birdDead;
}

void Bird::reset()
{
	pos = Vector2d(startPosX, startPosY);
	vel = Vector2d(birdSpeedX, birdSpeedY);
	birdDead = false;
}