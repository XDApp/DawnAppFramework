#pragma once

class DObject;
class DReference
{
public:
	DReference();
	~DReference();

	void PullReference(const DObject *Origin);
};

