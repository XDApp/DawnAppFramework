#pragma once

class DRSAKey
	: public DObject
{
	DClass(DRSAKey)
private:
	RSA *rsa;
	const char* DefaultPassword;
public:
	DRSAKey(unsigned long Key_Length);
	DRSAKey(RSA *Rsa);
	~DRSAKey();
	RSA* GetKey();

	RSA* GetPriKey();
	RSA* GetPubKey();
};

