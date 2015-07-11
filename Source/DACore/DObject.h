#pragma once

class DReference;
class DObject
{
protected:
	DReference *DF;
public:
	virtual const char* ClassName() const = 0;

	DObject();
	virtual ~DObject() = 0;

	//Copy Reference
	virtual void PullReference(const DObject *Origin);
};

