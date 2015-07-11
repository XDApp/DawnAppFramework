#include "stdafx.h"
#include "DEngineManager.h"
#include "DEventManager.h"
#include "DReference.h"

DEngineManager::DEngineManager()
	: BeforeInitialize(new DEventManager()),
	AfterInitialize(new DEventManager()),
	BeforeDispose(new DEventManager()),
	AfterDispose(new DEventManager()),
	WhenRender(new DEventManager()),
	WhenUpdate(new DEventManager()),
	WhenPullReference(new DEventManager())
{
}


DEngineManager::~DEngineManager()
{
	DDel(this->BeforeInitialize);
	DDel(this->AfterInitialize);
	DDel(this->BeforeDispose);
	DDel(this->AfterDispose);
	DDel(this->WhenUpdate);
	DDel(this->WhenRender);
	DDel(this->WhenPullReference);
}

void DEngineManager::Initialize()
{
	this->BeforeInitialize->Call(this);
	this->DF->EngineManager = this; 
	this->AfterInitialize->Call(this);
}

void DEngineManager::Dispose()
{
	this->BeforeDispose->Call(this);
	this->DF->EngineManager = nullptr;
	this->AfterDispose->Call(this);
}

void DEngineManager::Update()
{
	this->WhenUpdate->Call(this);
}

void DEngineManager::Render()
{
	this->WhenRender->Call(this);
}

void DEngineManager::PullReference(const DObject *Origin)
{
	DObject::PullReference(Origin);
	this->WhenPullReference->Call(this);
}