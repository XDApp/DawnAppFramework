#pragma once

class DObject;
typedef std::function<void(DObject*)> DEventCallback;

class DEventHandler :
	public DObject
{
	DClass(DEventHandler)
private:
	DEventCallback Callback;
public:
	DEventHandler(DEventCallback callback);
	~DEventHandler();

	//Run Event
	void Run(DObject* Sender);
};

