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
	std::vector<Asteroid> Enemies;
public:
	EnemyMgr(double __Delay, double __Difficulty,double __MinDelay) : Delay(0), Difficulty(__Difficulty),MaxDelay(__Delay),MinDelay(__MinDelay) { srand(al_get_time()); }
	bool ShouldSpawn();
	Vector RandomPosition();
	void CreateEnemies();
	void Update();


};
