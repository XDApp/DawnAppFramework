#pragma once

class DReference;
class DObject
{
public:
	DReference *DF;

	virtual const char* ClassName() const = 0;
	virtual const wchar_t* ClassName_W() const = 0;
	DObject();
	virtual ~DObject() = 0;

	//Copy Reference
	virtual void PullReference(const DObject *Origin);
};

