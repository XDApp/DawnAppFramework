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

int test_Crypt(void)
{
	char* buff = "I'm SkyZH!";
	unsigned char* __Ori = (unsigned char*)malloc(sizeof(char) * 200);
	unsigned char* __Dest = (unsigned char*)malloc(sizeof(char) * 200);

	memcpy(__Ori, buff, strlen(buff) + 1);

	size_t __DestSize = 200;
	size_t __OriSize = 200;
	DCryptRSA::Initialize();

	DRSAKey *Key = new DRSAKey(2048);
	
	EVP_PKEY *PubKey = DCryptRSA::ToEVP(Key->GetKey());
	EVP_PKEY *PriKey = DCryptRSA::ToEVP(Key->GetKey());

	DCryptRSA::EVP_Encrypt(PubKey, __Dest, __DestSize, __Ori, __OriSize);
	printf("Ciphertext is:\n");
	BIO_dump_fp(stdout, (const char *)__Dest, __DestSize);

	memset(__Ori, 0, sizeof(__Ori));
	DCryptRSA::EVP_Decrypt(PriKey, __Ori, __OriSize, __Dest, __DestSize);
	BIO_dump_fp(stdout, (const char *)__Ori, __OriSize);
	std::cout << __Ori << std::endl;

	DCryptRSA::EVP_Encrypt(PubKey, __Dest, __DestSize, __Ori, __OriSize);
	printf("Ciphertext is:\n");
	BIO_dump_fp(stdout, (const char *)__Dest, __DestSize);
	memset(__Ori, 0, sizeof(__Ori));

	DCryptRSA::EVP_Decrypt(PriKey, __Ori, __OriSize, __Dest, __DestSize);
	BIO_dump_fp(stdout, (const char *)__Ori, __OriSize);
	std::cout << __Ori << std::endl;


	DCryptRSA::Dispose();
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//DApp *App = new DApp();
	//App->Loop();
	test_Crypt();
	system("pause");
	return 0;
}

