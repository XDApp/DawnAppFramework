#pragma once

class DReference;
class DObject
{
protected:
	DReference *DF;
public:
	DObject();
	virtual ~DObject() = 0;
};

