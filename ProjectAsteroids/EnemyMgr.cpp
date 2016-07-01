#include <allegro5\allegro.h>
#include "Vector.h"
#include "Entity.h"
#include "Unit.h"
#include "MathHelper.h"
#include "Player.h"
#include "Asteroid.h"
#include "UnitMgr.h"
#include "Globals.h"
#include "EnemyMgr.h"

bool EnemyMgr::ShouldSpawn()
{
	if (al_get_time() >= Delay  + MinDelay)
	{
		Delay = al_get_time();
		return true;
	}
	return false;
}

Vector EnemyMgr::RandomPosition()
{
	//TODO: MAKE AN ALGORITHM
	return Vector(fmod(rand(),WIDTH),20);
}

void EnemyMgr::CreateEnemies()
{
	//if (ShouldSpawn())
	{
		//MaxDelay -= 0.25;
		//MinDelay /= 2;
		//MinDelay += 0.25;
		if(UnitMgr::mgrUnits.size() < MinDelay+10)
		for (int i = 10; i > 0; i--)
		{
			Asteroid* Enemy = new Asteroid(RandomPosition(), 5.0, Difficulty); 
			UnitMgr::AddToGroup(Enemy);
		}
		// Change size based on time, but we need time
		
		//Difficulty *= 1.25;
		if (Difficulty > 10)
			Difficulty = 10;
		else
			Difficulty *= 1.001;
		//Difficulty = fmod(Difficulty, 10);
		// No puedes & porque cuando llega al final desparece
		
	} // Aqui ves?

	// Do nothing
}
