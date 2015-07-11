#include "stdafx.h"
#include "DReference.h"


DReference::DReference()
	: EngineManager(nullptr),

	GraphicsManager(nullptr),
	WindowManager(nullptr),
	Window(nullptr),
	SceneManager(nullptr),
	Scene(nullptr),

	AudioManager(nullptr),

	NetworkManager(nullptr),

	ResourceManager(nullptr),

	DebugManager(nullptr),

	ConfigManager(nullptr)
{
}


DReference::~DReference()
{

}

void DReference::Clone(const DReference* DFReference)
{
	DReferenceObjectCopy(EngineManager);

	DReferenceObjectCopy(GraphicsManager);
	DReferenceObjectCopy(WindowManager);
	DReferenceObjectCopy(Window);
	DReferenceObjectCopy(SceneManager);
	DReferenceObjectCopy(Scene);

	DReferenceObjectCopy(AudioManager);

	DReferenceObjectCopy(NetworkManager);

	DReferenceObjectCopy(ResourceManager);

	DReferenceObjectCopy(DebugManager);

	DReferenceObjectCopy(ConfigManager);
}

bool DReference::CheckAvailable() const
{
	bool isAvailable = true;

	DReferenceObjectCheck(EngineManager);

	DReferenceObjectCheck(GraphicsManager);
	DReferenceObjectCheck(WindowManager);
	DReferenceObjectCheck(Window);
	DReferenceObjectCheck(SceneManager);
	DReferenceObjectCheck(Scene);

	DReferenceObjectCheck(AudioManager);

	DReferenceObjectCheck(NetworkManager);

	DReferenceObjectCheck(ResourceManager);

	DReferenceObjectCheck(DebugManager);

	DReferenceObjectCheck(ConfigManager);

	return isAvailable;
}