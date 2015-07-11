#include "stdafx.h"
#include "DEventHandler.h"


DEventHandler::DEventHandler(DEventCallback callback)
	:Callback(callback)
{
}


DEventHandler::~DEventHandler()
{
}

void DEventHandler::Run(DObject* Sender)
{
	this->Callback(Sender);
}
