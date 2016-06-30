#pragma once
class Vector
{
private:
	
public:
	double X;
	double Y;
	double Magnitude();
	Vector Normalize();
	Vector  operator+ (const Vector& other);
	void  operator+= (const Vector& other);
	Vector &operator-(const Vector& other);
	void operator=(const Vector& other);
	void operator=(const double &other);
	const bool &operator<(const Vector& other);
	const bool &operator<(const int &other);
	const Vector operator*(const Vector& other);
	const Vector operator*(const double& other);
	const Vector operator/(const double& other);
	const Vector operator/(const Vector& other);
	const bool & Vector::operator>(const int & other);
	//const Vector operator/ (const double num , const Vector& other);
	Vector(double iX, double iY) : X(iX), Y(iY){ /*NOTHING HERE*/}





};