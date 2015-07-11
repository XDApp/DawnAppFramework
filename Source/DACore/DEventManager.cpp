#include "stdafx.h"
#include "DEventHandler.h"
#include "DEventManager.h"


DEventManager::DEventManager()
{
}


DEventManager::~DEventManager()
{
}

void DEventManager::Call(DObject* Sender)
{
	for (DEventHandler* Callback : this->CallbackList)
	{
		Callback->Run(this);
	}
}
void DEventManager::AddHandler(DEventHandler *Callback)
{
	this->CallbackList.push_back(Callback);
}

void DEventManager::RemoveHandler(DEventHandler *Callback)
{
	this->CallbackList.erase(std::find(this->CallbackList.begin(), this->CallbackList.end(), Callback));
}