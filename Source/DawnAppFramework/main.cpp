#include "stdafx.h"
#include "DAppConfigManager.h"

DReference *GlobalDF;

class DApp
{
private:
	DEngineManager *Engine;
	DNServiceRunner *Manager;

public:
	DApp()
		: Engine(new DEngineManager())
	{
		GlobalDF = Engine->DF;
		this->Manager = new DNServiceRunner();
		this->Engine->BeforeInitialize->AddHandler(new DEventHandler([this](DObject* Sender)
		{
			Sender->DF->DebugManager = new DDebugManager();
			Sender->DF->ConfigManager = new DAppConfigManager();
		}));
		this->Engine->AfterDispose->AddHandler(new DEventHandler([this](DObject* Sender)
		{
			DDel(Sender->DF->DebugManager);
			DDel(Sender->DF->ConfigManager);
		}));
	};

	~DApp() 
	{
		DDel(this->Manager);
		DDel(this->Engine);
	};

	void Loop()
	{
		Manager->RunServ();
		DNUserLayer *userLayer = dynamic_cast<DNUserLayer*>(Manager->Service->UserLayer);

		DNCmdTokenReply* RTokenCmd = this->Manager->Service->Processor->ParseCmd<DNCmdTokenReply>(DNCmdType::ReplyToken);
		DNCmdToken* TokenCmd = this->Manager->Service->Processor->ParseCmd<DNCmdToken>(DNCmdType::Token);

		RTokenCmd->WhenRecv->AddHandler(new DEventHandler([](DObject *Sender){
			auto Data = dynamic_cast<DNTransData*>(Sender);
			char tmp[30];
			strncpy_s(tmp, Data->Data, Data->Size);
			if (Data) GlobalDF->DebugManager->Log(nullptr, DUtil::ANSIToUnicode(tmp).c_str());
		}));

		
		while (true)
		{
			TokenCmd->Send(DSocketAddrIn("192.168.0.105", 6000));
			Sleep(1000);
		}
		Manager->StopServ();

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

