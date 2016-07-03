#pragma once
 class Vector;
#include "Vector.h"
struct BBox
{
	Vector vHeight;
	Vector vWidth;
	BBox(double Width,double Height) : vHeight(Width,0) , vWidth(0,Height) {}
};