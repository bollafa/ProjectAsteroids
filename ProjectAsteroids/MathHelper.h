#pragma once
//
//
//	Useful Math Functions
//
//
#define PI 3.14159265
class Vector;
class Entity;
namespace Math
{
	/*
	*
	*	Collision check, round and box;
	*
	*
	*/

	bool CheckCollision(double& dSize, Vector& vSource, Vector& vTarget, bool bIsCircle = false);

	 Vector VectorDistanceBetweenEntities( Entity& Target, Entity& Source);
	 void VectorbyAngle(Vector& vVector,double &Angle, double &Mag);
	 double VectorAngle(Vector& pV);
	 Vector MakeVectorByRot(double Angle);
	 Vector ResultVectorOfForces(Vector& one, Vector& two, Vector& three, Vector& four); // may add ... arguments later
}