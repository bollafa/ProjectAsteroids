#pragma once
#include <vector>
class Vector;
class Entity;
class Unit;
class Player;
class Asteroid;
/*
*
*	Asteroids ask Global Class EnemyMgr whether they should attack ( : ) - ( : ) -  ( : )
*
*
*
*/
class EnemyMgr
{
private:
	double Delay;
	double Difficulty;
	double MaxDelay;
	double MinDelay;
public:
	EnemyMgr(double __Delay, double __Difficulty,double __MinDelay) : Delay(0), Difficulty(__Difficulty),MaxDelay(__Delay),MinDelay(__MinDelay) {}
	bool ShouldSpawn();
	Vector RandomPosition();
	void CreateEnemies();



};
