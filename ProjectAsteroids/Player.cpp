
#include "Vector.h"
#include "Entity.h"
#include "Unit.h"
#include "MathHelper.h"
#include "Player.h"
#include "Globals.h"
#include <allegro5\allegro_primitives.h>
#include <math.h>
void Player::Draw()
{
	//al_draw_filled_circle(vCoord.vCoord.X, vCoord.vCoord.Y, dSize, al_map_rgb(R, G, B));
	ALLEGRO_TRANSFORM trans;
	al_identity_transform(&trans);
	al_translate_transform(&trans, -vCoord.X, -vCoord.Y);
	al_rotate_transform(&trans, Math::VectorAngle(vDir));
	al_translate_transform(&trans, vCoord.X, vCoord.Y);

	al_use_transform(&trans);
	/* Draw whatevs here */
	al_draw_filled_rectangle(vCoord.X, vCoord.Y - 9, vCoord.X + 10, vCoord.Y - 7, al_map_rgb(255, 0, 0));
	al_draw_filled_rectangle(vCoord.X, vCoord.Y + 9, vCoord.X + 10, vCoord.Y + 7, al_map_rgb(255, 0, 0));



	al_draw_filled_triangle(vCoord.X - 12, vCoord.Y - 17, vCoord.X + 12, vCoord.Y, vCoord.X - 12, vCoord.Y + 17, al_map_rgb(255, 255, 0));
	al_draw_filled_rectangle(vCoord.X - 12, vCoord.Y - 2, vCoord.X + 15, vCoord.Y + 2, al_map_rgb(0, 0, 255));
	/* Turn off the rotation */
	al_identity_transform(&trans);
	al_use_transform(&trans);
	
}
void Player::ApplyForce(double Angle)
{
	//if(!bKeyForce)
		//vDir.X = cos(Angle) * dSpeed;
		Math::VectorbyAngle(vDir, Angle, dSpeed);
		double AAA = Math::VectorAngle(vDir);
		double crap = AAA * 180.0 / PI;
	//bKeyForce = true;
		
		al_draw_line(vCoord.X, vCoord.Y, vDir.X  + vCoord.X, vDir.Y   + vCoord.Y, al_map_rgb(255, 255, 0), 2);
		//al_put_pixel(vCoord.X+ vDir.X , vCoord.Y + vDir.Y , al_map_rgb(25, 255, 25));
		//al_draw_line(WIDTH / 2, HEIGHT / 2, vCoord.X + vDir.X, vCoord.Y + vDir.Y, al_map_rgb(25, 255, 25), 2);
}




void Player::MoveTo()
{
	Vector Right(0,0);
	Vector Left(0, 0);
	Vector Up(0, 0);
	Vector Down(0, 0);
	//vDir = 0;
	//vCoord += vDir;
	if (Movesc & 0b00000001) // RIGHT
		Right = Math::MakeVectorByRot(0);
	if (Movesc & 0b00000010) // LEFT
		Left = Math::MakeVectorByRot(180);
	if (Movesc & 0b00000100) // UP
		Up = Math::MakeVectorByRot(270);
	if (Movesc & 0b00001000) // DOWN
		Down = Math::MakeVectorByRot(90);
	
	if(Movesc !=0 && !OutOfBounds(- vDir.Magnitude()* 50))
	vDir = Math::ResultVectorOfForces(Right, Left, Up, Down);
	if (Movesc == 0)
		ApplyFriction();

	
	MoveToOppositePos();
	vCoord += vDir * dSpeed;
	
	al_draw_line(vCoord.X, vCoord.Y, vDir.X * 50 + vCoord.X, vDir.Y * 50 + vCoord.Y, al_map_rgb(255, 255, 0), 2);
	
	//al_draw_line(WIDTH / 2, HEIGHT / 2, vCoord.X * (-1), vCoord.Y * (-1) , al_map_rgb(255, 255, 255), 2);
	//al_draw_line(WIDTH / 2, HEIGHT / 2, WIDTH - vCoord.X , HEIGHT - vCoord.Y, al_map_rgb(255, 255, 255), 2);
}

void Player::ApplyFriction()
{
	vDir = vDir * 0.98;
}

/*void Player::MoveToOppositePos()
{
	if (OutOfBounds())
	{
		Vector vTemp = vCoord - Vector(WIDTH/2, HEIGHT/2);
		//vTemp.X = 10;
		//vTemp.Y = 500;
		vCoord.X = WIDTH - vCoord.X ;
		vCoord.Y =  HEIGHT- vCoord.Y;

		al_draw_line(WIDTH / 2, HEIGHT / 2, (vCoord.X +vTemp.X )* 1,(vCoord.Y +  vTemp.Y ) * 1, al_map_rgb(100, 100, 255), 2);
		vCoord = vCoord + vDir;

	}
	
}*/

void Player::RequestMove(uint8_t binary,uint8_t shift)
{
	
	/*if ((Movesc ^ binary) && !(Movesc & binary))
		Movesc ^= binary;
	else
	{
		Movesc &= binary;
	}*/
	Movesc ^= (-binary^Movesc) & (1 << shift);
}

void Player::Update()
{
	//MoveTo();
	//MoveToOppositePos();
	MoveTo();
	Draw();
}

