#pragma once
#include "DManager.h"
class DEngineManager :
	public DManager
{
public:
	DEngineManager();
	~DEngineManager();

	void Initialize() override;
	void Dispose() override;

	void Update() override;
	void Render() override;

	void PullReference(const DObject *Origin) override;
};

