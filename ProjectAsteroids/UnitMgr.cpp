#include "Vector.h"
#include "Entity.h"
#include "Unit.h"

#include "UnitMgr.h"
#include "Globals.h"
//#include "Player.h"
#include "MathHelper.h"
#include <memory>
#include <list>
#include <forward_list>
 std::vector<std::shared_ptr<Unit>> UnitMgr::mgrUnits; // Yuhu , dont Forget the UnitMgr:: !!!!!!!!!!!!!!!!!!!!
 void UnitMgr::AddToGroup(Unit* uLiving)
{
	mgrUnits.push_back((std::shared_ptr<Unit>(uLiving)));
}

/*
*
*	TODO: NOTHING! Well, it'll probably crash so ... whatever
*
*/
 void UnitMgr::UpdateUnits()
{
	/*for (auto it = mgrUnits.begin(); it != mgrUnits.end();)
	{
		for (auto wt = mgrUnits.begin(); wt != mgrUnits.end();)
		{
			//if (Math::CheckCollision(it->GetSize(), it->GetCoords(), wt->GetCoords()))
			{
				
				if (!((*it) == (*wt)))
				{
					/*
					*	Possibly Call to Unit.Die()
					*
					wt = mgrUnits.erase(wt);
				}
				else
				{
					wt->Update();

					++wt;
				}
			}
			
		}
		if (it != mgrUnits.end() && it != mgrUnits.begin())
			++it;

	}*/ // FIX LATER
	 auto it = mgrUnits.begin();
	if(!mgrUnits.empty())
	do
	{
		/*if ((*it)->OutOfBounds())
			it = mgrUnits.erase(it);
		
		else*/
		{
			(*it)->Update();
			++it;

		}
	} while (it != mgrUnits.end());

}
