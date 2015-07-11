#pragma once
#include "DManager.h"

class DEventManager;

class DEngineManager :
	public DManager
{
	DClass(DEngineManager)
public:
	DEngineManager();
	~DEngineManager();

	void Initialize() override;
	void Dispose() override;

	void Update() override;
	void Render() override;

	void PullReference(const DObject *Origin) override;

	DEventManager* BeforeInitialize;
	DEventManager* AfterInitialize;
	DEventManager* BeforeDispose;
	DEventManager* AfterDispose;

	DEventManager* WhenUpdate;
	DEventManager* WhenRender;
	DEventManager* WhenPullReference;
};

