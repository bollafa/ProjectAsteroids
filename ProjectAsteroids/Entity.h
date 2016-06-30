#pragma once
class Vector;

class Entity 
{
protected:
    Vector vCoord;
	Vector vSpeed;
	Vector vDir;
public:
	Entity(Vector ivCoord) : vCoord(ivCoord.X,ivCoord.Y) , vSpeed(0,0),vDir(0,0) {}
	virtual bool operator== (Entity& other);
	
	virtual void Update() {} 
	Vector & GetCoords() { return vCoord; }
};