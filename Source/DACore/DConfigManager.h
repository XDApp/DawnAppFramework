#pragma once
#include "DObject.h"
class DConfigManager :
	public DObject
{
	DClass(DConfigManager)
public:
	DConfigManager();
	~DConfigManager();

	virtual void Load() = 0;
	virtual void Save() = 0;
};

