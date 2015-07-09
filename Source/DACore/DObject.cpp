#include "stdafx.h"
#include "DObject.h"
#include "DReference.h"

DObject::DObject()
	: DF(new DReference)
{
}


DObject::~DObject()
{
}
