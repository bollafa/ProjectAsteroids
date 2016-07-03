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

	}*/ // FIX LATER !!!!!!!!!!!!!!!!!!
	
	 auto it = mgrUnits.begin();
	if(!mgrUnits.empty())
	do
	{
		
		{
			(*it)->Update();
			++it;

		}
	} while (it != mgrUnits.end());

}

bool UnitMgr::CheckCollision(Unit &One, Unit &Two) // Target , Source
{
	//Vector distance (((One.vCoord.X+One.Bounds.vWidth) - (Two.vCoord+Two.Bounds.vWidth)), ((One.vCoord + One.Bounds.vHeight) - (Two.vCoord + Two.Bounds.vHeight)));
	//Vector XDistance = ((One.vCoord + One.Bounds.vWidth) - (Two.vCoord + Two.Bounds.vWidth));
	//Vector YDistance = ((One.vCoord + One.Bounds.vHeight) - (Two.vCoord + Two.Bounds.vHeight));
	Vector ProjectionDistance = (One.vCoord) - (Two.vCoord);
	ProjectionDistance = ProjectionDistance * ProjectionDistance;
	double Size = One.dSize + Two.dSize;
	Size *= Size;
	//printf("%f",  Size);
	return (ProjectionDistance < Size);

}

void UnitMgr::UpdateCollision()
{
	auto pt = mgrUnits.begin(); //BEGIn

	bool Deleted = false;
	if (!mgrUnits.empty())
		do
		{
			/* auto jp = mgrUnits.begin();
			do
			{


			} while (jp != mgrUnits.end());*/
			for (auto jp = mgrUnits.begin(); jp != mgrUnits.end(); ++jp)
			{
				if (CheckCollision(*jp->get(), *pt->get()) && jp != pt)
				{
					printf("Collosion!\t");
					Deleted = true;
					//jp = mgrUnits.erase(jp);

				}


			}
			if (!Deleted)
			{

				++pt;
			}
			else
			{
				Deleted = false;
				pt = mgrUnits.erase(pt);
			}



		} while (pt != mgrUnits.end());//END
}
