#include "Vector.h"
#include "Entity.h"
#include "Unit.h"
#include "MathHelper.h"
#include "Player.h"
#include "Globals.h"
#include <allegro5\allegro_primitives.h>
#include <math.h>
#include "Cannon.h"

void Cannon::RegisterShoot(uint8_t binary, uint8_t shift)
{
	bType ^= (-binary^bType) & (1 << shift);
}

void Cannon::Draw()
{
	al_draw_line(vCoord.X, vCoord.Y , vCoord.X + vDir.X , vCoord.Y + vDir.Y , al_map_rgba((255 * 100) / 255, (0 * 100) / 255, (0 * 100) / 255, 100), 2);
	ALLEGRO_TRANSFORM trans;
	al_identity_transform(&trans);
	al_translate_transform(&trans, -vCoord.X, -vCoord.Y);
	al_rotate_transform(&trans, Math::VectorAngle(vDir));
	al_translate_transform(&trans, vCoord.X, vCoord.Y);

	al_use_transform(&trans);
	/* Draw whatevs here */
	al_draw_filled_rectangle(vCoord.X, vCoord.Y, vCoord.X + 30, vCoord.Y + 5, al_map_rgb(255, 25, 200));
	
	/* Turn off the rotation */
	al_identity_transform(&trans);
	al_use_transform(&trans);
	
}

void Cannon::MoveTo(int X , int Y)
{
	Vector vTemp = Vector(X, Y) - vCoord;
	vDir = vTemp;
	
}
