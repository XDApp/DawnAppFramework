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

void DRSAKey::WritePubBuf()
{
	keybio = BIO_new(BIO_s_mem());
	if (keybio == nullptr)
	{
		GlobalDF->DebugManager->ThrowError<DCryptException>(nullptr, L"Failed to create key BIO");
		return;
	}
	PEM_write_bio_RSAPublicKey(keybio, this->rsa);
}

void DRSAKey::WritePriBuf()
{
	keybio = BIO_new(BIO_s_mem());
	if (keybio == nullptr)
	{
		GlobalDF->DebugManager->ThrowError<DCryptException>(nullptr, L"Failed to create key BIO");
		return;
	}
	PEM_write_bio_RSAPrivateKey(keybio, this->rsa, nullptr, nullptr, -1, nullptr, nullptr);
}


RSA* DRSAKey::GetPubKey()
{
	this->WritePubBuf();
	RSA *result = nullptr;
	
	BIO_reset(this->keybio);

	if (keybio == nullptr)
	{
		GlobalDF->DebugManager->ThrowError<DCryptException>(nullptr, L"Failed to create key BIO");
		return 0;
	}
	result = PEM_read_bio_RSA_PUBKEY(keybio, &this->rsa, NULL, NULL);
	BIO_free_all(keybio);
	return result;
}

RSA* DRSAKey::GetPriKey()
{
	this->WritePriBuf();
	RSA *result = nullptr;

	BIO_reset(this->keybio);

	if (keybio == nullptr)
	{
		GlobalDF->DebugManager->ThrowError<DCryptException>(nullptr, L"Failed to create key BIO");
		return 0;
	}
	result = PEM_read_bio_RSAPrivateKey(keybio, &this->rsa, NULL, NULL);
	BIO_free_all(keybio);
	return result;
}
