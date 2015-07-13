#pragma once
#include "DConfigManager.h"
class DCoreConfigManager :
	virtual public DConfigManager
{
	DClass(DCoreConfigManager)
public:
	DCoreConfigManager();
	~DCoreConfigManager();
protected:
	virtual void Load() override;
	virtual void Save() override;
};

