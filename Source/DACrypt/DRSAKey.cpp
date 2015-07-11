#include "stdafx.h"
#include "DRSAKey.h"
#include "DCryptException.h"

const int DRSAKEY_RAND_BUFFER = 1000;
DRSAKey::DRSAKey(unsigned long Key_Length)
	: rsa(nullptr)
{
	rsa = RSA_generate_key(Key_Length, RSA_F4, NULL, NULL);
	if (rsa == NULL)
	{
		GlobalDF->DebugManager->ThrowError<DCryptException>(this, L"RSA Generate Error");
	}
}

DRSAKey::DRSAKey(RSA *Rsa)
	:rsa(Rsa)
{

}


DRSAKey::~DRSAKey()
{
	RSA_free(rsa);
}

RSA* DRSAKey::GetKey()
{
	return rsa;
}