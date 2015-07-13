#include "stdafx.h"
#include "DRSAKey.h"
#include "DCryptException.h"

const int DRSAKEY_RAND_BUFFER = 1000;
DRSAKey::DRSAKey(unsigned long Key_Length)
	: rsa(nullptr),
	DefaultPassword("asdfghjkl")
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

RSA* DRSAKey::GetPubKey()
{
	BIO *keybio = nullptr;
	keybio = BIO_new(BIO_s_mem());
	if (keybio == nullptr)
	{
		GlobalDF->DebugManager->ThrowError<DCryptException>(nullptr, L"Failed to create key BIO");
		return nullptr;
	}
	PEM_write_bio_RSAPublicKey(keybio, this->rsa);

	RSA *result = nullptr;
	
	if (keybio == nullptr)
	{
		GlobalDF->DebugManager->ThrowError<DCryptException>(nullptr, L"Failed to create key BIO");
		return nullptr;
	}
	
	PEM_read_bio_RSAPublicKey(keybio, &result, nullptr, nullptr);
	BIO_free(keybio);

	return result;
}

RSA* DRSAKey::GetPriKey()
{
	BIO *keybio = nullptr;
	keybio = BIO_new(BIO_s_mem());
	if (keybio == nullptr)
	{
		GlobalDF->DebugManager->ThrowError<DCryptException>(nullptr, L"Failed to create key BIO");
		return nullptr;
	}
	PEM_write_bio_RSAPrivateKey(keybio, this->rsa, EVP_des_ede3_cbc(), nullptr, -1, nullptr, (void *)this->DefaultPassword);

	RSA *result = nullptr;
	
	if (keybio == nullptr)
	{
		GlobalDF->DebugManager->ThrowError<DCryptException>(nullptr, L"Failed to create key BIO");
		return nullptr;
	}

	PEM_read_bio_RSAPrivateKey(keybio, &result, nullptr, (void *)this->DefaultPassword);
	BIO_free(keybio);
	
	return result;
}
