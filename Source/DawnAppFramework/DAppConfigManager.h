#pragma once

class DAppConfigManager :
	public DConfigManager
{
public:
	DAppConfigManager();
	~DAppConfigManager();

	void Load();
	void Save();

	EVP_PKEY *RSAKey;
};

