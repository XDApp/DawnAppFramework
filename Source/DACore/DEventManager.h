#pragma once
#include "DObject.h"
#include "DEventHandler.h"

class DEventHandler;

class DEventManager :
	public DObject
{
	DClass(DEventManager)
	std::vector<DEventHandler*>CallbackList;
public:
	DEventManager();
	~DEventManager();
	void Call(DObject* Sender);
	void AddHandler(DEventHandler *Callback);
	void RemoveHandler(DEventHandler *Callback);
};

