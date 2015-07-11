#include "stdafx.h"

DReference *GlobalDF;

class DApp
{
private:
	DEngineManager *Engine;
public:
	DApp()
		: Engine(new DEngineManager())
	{
		GlobalDF = Engine->DF;
		this->Engine->BeforeInitialize->AddHandler(new DEventHandler([](DObject* Sender)
		{
			Sender->DF->DebugManager = new DDebugManager();
		}));
		this->Engine->AfterDispose->AddHandler(new DEventHandler([](DObject* Sender)
		{
			DDel(Sender->DF->DebugManager);
		}));
	};

	~DApp() 
	{
		DDel(this->Engine);
	};

	void Loop()
	{
		this->Engine->Update();
		this->Engine->Render();
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	DApp *App = new DApp();
	App->Loop();
	system("pause");
	return 0;
}

