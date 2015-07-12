#pragma once

class DRSAKey
	: public DObject
{
	DClass(DRSAKey)
private:
	RSA *rsa;
	BIO *keybio;
public:
	DRSAKey(unsigned long Key_Length);
	DRSAKey(RSA *Rsa);
	~DRSAKey();
	RSA* GetKey();

	RSA* GetPriKey();
	RSA* GetPubKey();

	void WritePubBuf();
	void WritePriBuf();

};

