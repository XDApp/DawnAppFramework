#include "stdafx.h"
#include "DObject.h"
#include "DReference.h"

DObject::DObject()
	: DF(new DReference)
{
}


DObject::~DObject()
{
	DDel(this->DF);
}

void DObject::PullReference(const DObject* Object)
{
	this->DF->Clone(Object->DF);
}