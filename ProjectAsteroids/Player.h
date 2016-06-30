#pragma once
class Vector;
class Entity;
class Unit;
#include <stdint.h>
class Player : public Unit
{
private:
	bool bKeyForce;
	uint8_t Movesc;
	/* 
		0000 - garbage - 0000 : FROM LEFT TO RIGHT : DOWN-UP-LEFT-RIGHT
	*/
public:
	Player(Vector ivCoord) : Unit(ivCoord) { R = 66; G = 133; B = 244; }
	Player(Vector ivCoord, double __dSize, double aSpeed) : Unit(ivCoord, __dSize, aSpeed), bKeyForce(false) , Movesc(0b00000000){R = 66; G = 133; B = 244; vDir.X = 0;}
	void Draw();
	bool ShouldMove() { return bKeyForce; }
	void ApplyForce(double Angle);
	void MoveTo();
	void ApplyFriction();
	//void MoveToOppositePos();
	void RequestMove(uint8_t binary,uint8_t shift);
	void Update();





};