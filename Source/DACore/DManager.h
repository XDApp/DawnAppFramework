#pragma once
#include "DObject.h"
class DManager :
	public DObject
{
	DClass(DManager)
public:
	DManager();
	virtual ~DManager() = 0;

	virtual void Initialize() = 0;
	virtual void Dispose() = 0;

	virtual void Update() = 0;
	virtual void Render() = 0;
};

