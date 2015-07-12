#include "stdafx.h"
#include "DAppConfigManager.h"

DReference *GlobalDF;

extern EVP_PKEY *___Data_TMP_Key;

class DApp
{
private:
	DEngineManager *Engine;
	DNServiceRunner *Manager;

public:
	DApp()
		: Engine(new DEngineManager())
	{
		DCryptRSA::Initialize();

		GlobalDF = Engine->DF;
		this->Manager = new DNServiceRunner();
		this->Engine->BeforeInitialize->AddHandler(new DEventHandler([this](DObject* Sender)
		{
			DAppConfigManager *ConfigManager = new DAppConfigManager();

			Sender->DF->DebugManager = new DDebugManager();
			Sender->DF->ConfigManager = ConfigManager;

			DRSAKey *Key = new DRSAKey(2048);
			___Data_TMP_Key = ConfigManager->RSAKey = DCryptRSA::ToEVP(Key->GetKey());
			DDel(Key);
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

		DCryptRSA::Dispose();
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
			if (Data) GlobalDF->DebugManager->Log(nullptr, (L"Token Recved: " + DUtil::ANSIToUnicode(tmp)).c_str());
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

