#pragma once
#include "DObject.h"

//Clone Object
#define DReferenceObjectCopy(ClassName)\
	this->ClassName = (DFReference->ClassName != nullptr) ? (DFReference->ClassName) : (this->ClassName)
//Check Object
#define DReferenceObjectCheck(ClassName)\
	isAvailable = (isAvailable&&((this->ClassName)!=nullptr))

class DEngineManager;

class DGraphicsManager;
class DWindowManager;
class DWindow;
class DSceneManager;
class DScene;

class DAudioManager;

class DNetworkManager;

class DResourceManager;

class DDebugManager;

class DConfigManager;

class DReference
{
public:
	DReference();
	~DReference();

	//Copy Reference
	void Clone(const DReference* DFReference);
	//Check if a scene can use this DF object
	bool CheckAvailable() const;

	DEngineManager* EngineManager;

	DGraphicsManager* GraphicsManager;
	DWindowManager* WindowManager;
	DWindow* Window;
	DSceneManager* SceneManager;
	DScene* Scene;

	DAudioManager* AudioManager;

	DNetworkManager* NetworkManager;

	DResourceManager* ResourceManager;

	DDebugManager* DebugManager;

	DConfigManager* ConfigManager;
};
