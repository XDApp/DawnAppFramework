#pragma once
#include "DObject.h"
class DConfigManager :
	public DObject
{
	DClass(DConfigManager)
public:
	DConfigManager();
	~DConfigManager();
	template<class ConfigClass> ConfigClass* GetConfig()
	{
		return dynamic_cast<ConfigClass*>(this);
	}
protected:
	virtual void Load() = 0;
	virtual void Save() = 0;
};

