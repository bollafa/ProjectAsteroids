#include "Vector.h"
#include <math.h>
double Vector::Magnitude()
{
	return sqrt(X*X+Y*Y);
}
Vector Vector::Normalize()
{
	double TempX = X/ Magnitude();
	double TempY = Y / Magnitude();
	return (Vector(TempX, TempY));
}
/*
*	Sums a vector with another one
*
*/
Vector  Vector::operator+(const Vector & other)
{
	double iTempX = X + other.X;
	double iTempY = Y + other.Y;

	return Vector(iTempX,iTempY);
}

/*
*	Overloaded Plus Sum += operator
*	X = Other.X + X and Y = Other.Y + Y
*	Return type : void
*/
 void Vector::operator+=(const Vector & other)
{
		X += other.X;
		Y += other.Y;
	
}

 Vector & Vector::operator-(const Vector & other)
 {
	 return Vector(X - other.X, Y - other.Y);
 }

void  Vector::operator=(const Vector & other)
 {
	 // TODO: insert return statement here
	 X = other.X;
	 Y = other.Y;
	 //return Vector(other.X, other.Y);
 }

void Vector::operator=(const double & other)
{
	X = other;
	Y = other;
}

 const bool & Vector::operator<(const Vector & other)
 {
	 // TODO: insert return statement here
	 return ((fabs(X) < other.X && fabs(Y) < other.Y));
 }

 const bool & Vector::operator<(const int & other)
 {
	 // TODO: insert return statement here
	 return ((fabs(X) < other && fabs(Y) < other));
 }
 const bool & Vector::operator>(const int & other)
 {
	 // TODO: insert return statement here
	 return ((fabs(X) > other && fabs(Y) > other));
 }
 const Vector  Vector::operator*(const Vector & other)
 {
	 // TODO: insert return statement here
	 return (Vector(X*other.X, Y*other.Y));

 }

 const Vector  Vector::operator*(const double & other)
 {
	 // TODO: insert return statement here
	 return (Vector(X*other, Y*other));
 }

 const Vector Vector::operator/(const double & other)
 {
	 return(Vector(X/other, Y/other));
 }

 const Vector Vector::operator/(const Vector & other)
 {
	 return (Vector(X/other.X, Y/other.Y));;
 }
