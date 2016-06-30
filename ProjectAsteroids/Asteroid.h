#pragma once
/*
*	4a 6f 6e 61 74 68 61 6e 20 43 6f 75 6c 74 6f 6e 0d 0a 
*/
class Vector;
class Entity;
class Unit;
class Player;
extern Player* pPlayer;
class Asteroid :  public Unit
{
private:
	double InitAngle;
	Vector InitialVector;
public:
	Asteroid(Vector ivCoord, double Size, double tSpeed) : Unit(ivCoord, Size,tSpeed),InitAngle(Math::VectorAngle(Math::VectorDistanceBetweenEntities(*pPlayer, *this))), InitialVector(Math::VectorDistanceBetweenEntities(*pPlayer, *this)) { R = 0; G = 255; B = 0; }

	 void Draw() ;
	 void MoveTo();




};