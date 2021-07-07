#include "GameManager.h"

GameManager::GameManager(std::vector<Tube>* t, std::vector<Apple>* a)
{
	tubes = t;
	apples = a;
	Init();
}

void GameManager::Init()
{
	score = 0;
	timeFromLastTube = 0;
	curDelay = startTubeDelay;
	tubes->clear();
}

void GameManager::passTime(double dt)
{
	timeFromLastTube += dt;
	if (timeFromLastTube > curDelay)
	{
		timeFromLastTube -= curDelay;
		curDelay -= delayDecrease;
		tubes->push_back(Tube(SCREEN_WIDTH + 50, SCREEN_HEIGHT / 5 + rand() % 300,
			tubeSpeed, 0, 48, rand() % 100 + 200));
		if (rand() % 100 > 33)
		{
			auto t = tubes->end() - 1;
			apples->push_back(Apple(t->getX() + 14, t->getY() + (rand() % (t->getH() - 50) + 25), 
				tubeSpeed, 0, 20, 20));
		}
		curDelay += delayDecrease;
	}
}

void GameManager::dead()
{
	if (score > topScore)
		topScore = score;
}

void GameManager::addScore(double points)
{
	score += points;
}

void GameManager::setHiScore(double points)
{
	topScore = points;
}

int GameManager::getScore()
{
	return int(score);
}

int GameManager::getTopScore()
{
	return topScore;
}
