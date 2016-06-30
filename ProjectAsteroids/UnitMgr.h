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

	 extern  std::list<std::shared_ptr<Unit>> mgrUnits;
	
	 void AddToGroup(Unit* uLiving);
	 void UpdateUnits();
	

}
