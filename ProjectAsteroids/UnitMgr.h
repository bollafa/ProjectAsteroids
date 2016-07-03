#pragma once
#include <vector>
#include < memory>
#include <list>
class Vector;
class Entity;
class Unit;
class Player;
namespace UnitMgr
{

	 extern  std::vector<std::shared_ptr<Unit>> mgrUnits;
	
	 void AddToGroup(Unit* uLiving);
	extern inline void UpdateUnits();
	bool CheckCollision(Unit &One, Unit &Two);
	void UpdateCollision();
}
