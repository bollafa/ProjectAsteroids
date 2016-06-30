#include "Vector.h"
#include "Entity.h"

#include <typeinfo>
#include <iostream>
bool Entity::operator==(Entity & other)
{
	
	if (typeid(other) == typeid(this))
		return true;
	return false;
}
