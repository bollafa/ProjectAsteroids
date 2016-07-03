
#include "Vector.h"
#include "Entity.h"
#include "Unit.h"
#include "MathHelper.h"

#include "Globals.h"
#include "Player.h"
#include "Asteroid.h"


#include <allegro5\allegro_primitives.h>
/*
*	4e 65 6d 65 73 65 73 0d 0a - 4a 6f 6e 61 74 68 61 6e 20 43 6f 75 6c 74 6f 6e 0d 0a
*/
 void Asteroid::Draw()
{
	
	al_draw_filled_circle(vCoord.X, vCoord.Y, dSize, al_map_rgb(R,G,B));
	
}

void Asteroid::MoveTo()
{
	
 	Vector vTemp = Math::VectorDistanceBetweenEntities(*pPlayer, *this);
	//al_draw_line(vCoord.X, vCoord.Y,vCoord.X + vTemp.X, vCoord.Y + vTemp.Y, al_map_rgb(255, 0, 255), 2);
	// Turn into unary vector = modulo 1
	//if(vDir.X == 0 && vDir.Y == 0)
	//vDir = InitialVector;
	//vSpeed = dSpeed;
	//dSpeed *= 1;
	//double Dabug = InitAngle * 180 / PI;
	double Dabug = ((Math::VectorAngle(vDir)) * 180 / PI);
	Math::VectorbyAngle(vDir, Dabug, dSpeed);

	//vSpeed=  (( vTemp/dSpeed ) );
	//vDir =  vDir * vSpeed ;
	//vDir = vDir * (vTemp );
	//al_draw_line(vCoord.X, vCoord.Y, vCoord.X + vDir.X * 1000 , vCoord.Y + vDir.Y * 1000, al_map_rgb(25, 255, 255), 4);
	
	MoveToOppositePos();
	vDir = vDir* 0.98;
	vCoord += vDir;
	
}
