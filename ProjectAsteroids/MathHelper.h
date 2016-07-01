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

	inline bool CheckCollision(double& dSize, Vector& vSource, Vector& vTarget, bool bIsCircle = false);

	 extern inline   Vector VectorDistanceBetweenEntities( Entity& Target, Entity& Source);
	 extern inline void VectorbyAngle(Vector& vVector,double &Angle, double &Mag);
	 extern inline double VectorAngle(Vector& pV);
	 extern inline Vector MakeVectorByRot(double Angle);
	 extern inline Vector ResultVectorOfForces(Vector& one, Vector& two, Vector& three, Vector& four); // may add ... arguments later
}