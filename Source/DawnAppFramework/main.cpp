#include "stdafx.h"

class DApp
{
private:
	DEngineManager *Engine;
public:
	DApp()
		: Engine(new DEngineManager())
	{

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
	return 0;
}

