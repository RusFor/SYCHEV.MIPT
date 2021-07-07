#pragma once
#include <vector>
#include "Tube.h"
#include "Apples.h"

const double startTubeDelay = 2.0;
const double delayDecrease = 0.05;

class GameManager
{
	double score;
	double topScore;
	double timeFromLastTube;
	double curDelay;
	std::vector<Tube> *tubes;
	std::vector<Apple> *apples;
public:
	GameManager(std::vector<Tube>* t, std::vector<Apple>* a);
	void Init();
	void passTime(double dt);
	void dead();

	void addScore(double points);
	void setHiScore(double points);
	int getScore();
	int getTopScore();
};