#pragma once
//
//	Rectangles Looking at mouse, shoot pellets
//
//
//
class Vector;
class Entity;
class Unit;
#include <stdint.h>
class Cannon : public Unit
{
private:
	uint8_t bType;
public:
	Cannon(Vector vPos) : Unit(vPos), bType(0) {}
	void RegisterShoot(uint8_t binary, uint8_t shift);
	void Draw();
	void MoveTo(int X, int Y);
};