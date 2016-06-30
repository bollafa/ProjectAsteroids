#pragma once
class Vector;
class Entity;
class Unit : public Entity
{
protected:
	double dSize;
	int R;
	int G;
	int B;
	Vector vDir;
	double dSpeed;
public:
	Unit(Vector ivCoord) : Entity(ivCoord), dSize(0), R(0),G(0),B(0) ,vDir(0,0) {}
	Unit(Vector ivCoord,double __dSize,double tSpeed) : Entity(ivCoord), dSize(__dSize), R(255), G(255), B(255), vDir(0,0), dSpeed(tSpeed) {}
	virtual void Update();
	virtual void MoveTo() {};
	virtual void Draw() {};
	void SetColors(int iR, int iG, int iB) { R = iR; G = iG; B = iB; }
	const double GetSize() { return dSize; }
	bool OutOfBounds(int offset = 0);
	void MoveToOppositePos();
};