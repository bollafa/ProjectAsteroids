#include "Vector.h"
#include "Entity.h"
#include "MathHelper.h"
#include "Globals.h"
#include "Unit.h"
#include <math.h>
#include <allegro5\allegro_primitives.h>
void Unit::Update()
{
	MoveTo();
	Draw();
}

bool Unit::OutOfBounds(int offset )
{
	Vector vTemp =  vCoord - Vector(0,0) ;
	//al_draw_line(0, 0, vCoord.X, vCoord.Y, al_map_rgb(255, 255, 255), 2);
	if ( ( ( (vTemp.X)  >   WIDTH + offset ) || ((vTemp.X)  < 0 - offset)) || (((vTemp.Y)  >   HEIGHT + offset) || ((vTemp.Y)  < 0 - offset)) )
		return true;
	
	return false;
}

void Unit::MoveToOppositePos()
{
	if (OutOfBounds())
	{
		Vector vTemp = vCoord - Vector(WIDTH / 2, HEIGHT / 2);
		//vTemp.X = 10;
		//vTemp.Y = 500;
		vCoord.X = WIDTH - vCoord.X;
		vCoord.Y = HEIGHT - vCoord.Y;

		al_draw_line(WIDTH / 2, HEIGHT / 2, (vCoord.X + vTemp.X) * 1, (vCoord.Y + vTemp.Y) * 1, al_map_rgb(100, 100, 255), 2);
		vCoord = vCoord + vDir;

	}
}
