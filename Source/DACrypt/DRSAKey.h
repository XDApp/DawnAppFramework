#pragma once

class DRSAKey
	: public DObject
{
private:
	RSA *rsa;
public:
	DRSAKey(unsigned long Key_Length);
	DRSAKey(RSA *Rsa);
	~DRSAKey();
	RSA* GetKey();
};

