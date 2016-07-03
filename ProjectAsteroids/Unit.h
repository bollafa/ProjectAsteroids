#pragma once
class Vector;
class Entity;
#include "BBox.h"
#include "UnitMgr.h"
class Unit : public Entity
{

protected:
	double dSize;
	int R;
	int G;
	int B;
	Vector vDir;
	double dSpeed;
	BBox Bounds;
public:
	Unit(Vector ivCoord) : Entity(ivCoord), dSize(0), R(0),G(0),B(0) ,vDir(0,0) ,Bounds(0,0){}
	Unit(Vector ivCoord,double __dSize,double tSpeed) : Entity(ivCoord), dSize(__dSize), R(255), G(255), B(255), vDir(0,0), dSpeed(tSpeed) ,Bounds(0,0){}
	Unit(Vector ivCoord,double __dSize,double tSpeed,BBox CBox) : Entity(ivCoord),dSize(__dSize), R(255), G(255), B(255), vDir(0, 0), dSpeed(tSpeed), Bounds(CBox) {}
	virtual void Update() ;
	 virtual void MoveTo() {};
	 virtual void Draw() {};
	void SetColors(int iR, int iG, int iB) { R = iR; G = iG; B = iB; }
	const double GetSize() { return dSize; }
	bool OutOfBounds(int offset = 0);
	void MoveToOppositePos();
	friend bool UnitMgr::CheckCollision(Unit &One, Unit &Two);
};