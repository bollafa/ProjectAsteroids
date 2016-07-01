#include "Vector.h"
#include "Entity.h"
#include "MathHelper.h"
#include <math.h>

 bool Math::CheckCollision( double &dSize, Vector &vSource, Vector &vTarget, bool bIsCircle)
{
	Vector Temp = vTarget - vSource;
	if(Temp < dSize)
		return true;

	return false;

}

 inline Vector Math::VectorDistanceBetweenEntities( Entity& Target, Entity& Source)
{
	
	return Vector((Target.GetCoords() - Source.GetCoords()));
}

 void Math::VectorbyAngle(Vector& vVector, double &Angle, double &Mag)
{
	Angle = Angle * PI / 180;
	vVector.X = cos(Angle) * Mag;
	vVector.Y = sin(Angle) * Mag;
}

 double Math::VectorAngle(Vector& pV)
{
	double Debugger = atan2(pV.Y, pV.X);
	return atan2(pV.Y, pV.X);
}

 Vector Math::MakeVectorByRot(double Angle)
{
	Angle = Angle * PI / 180;
	Vector vTemp(cos(Angle), sin(Angle));
	return vTemp;
}

 Vector Math::ResultVectorOfForces(Vector& one, Vector& two, Vector& three, Vector& four)
{

	return one + two + three + four;
}
