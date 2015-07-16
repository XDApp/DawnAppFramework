#include "stdafx.h"
#include "DCryptAES.h"
#include "DAESKey.h"
#include "DCryptException.h"

DCryptAES::DCryptAES()
{
}


DCryptAES::~DCryptAES()
{
}

void DCryptAES::AES_Encrypt(DAESKey *key, unsigned char* &Crypt, size_t &CryptLength, const unsigned char* Origin, const size_t OriginLength, const unsigned char* iv)
{
	EVP_CIPHER_CTX *ctx;

	int len;

	if (!(ctx = EVP_CIPHER_CTX_new()))
		GlobalDF->DebugManager->ThrowError<DCryptException>(nullptr, L"Failed to create Context");

	if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, key->GetKey(), iv))
		GlobalDF->DebugManager->ThrowError<DCryptException>(nullptr, L"Failed to initialize encrypt");

	if (1 != EVP_EncryptUpdate(ctx, Crypt, &len, Origin, OriginLength))
		GlobalDF->DebugManager->ThrowError<DCryptException>(nullptr, L"Failed to update encrypt");
	
	CryptLength = len;

	if (1 != EVP_EncryptFinal_ex(ctx, Crypt + len, &len))
		GlobalDF->DebugManager->ThrowError<DCryptException>(nullptr, L"Failed to final encrypt");

	CryptLength += len;

	EVP_CIPHER_CTX_free(ctx);
}

void DCryptAES::AES_Decrypt(DAESKey *key, unsigned char* &Crypt, size_t &CryptLength, const unsigned char* Origin, const size_t OriginLength, const unsigned char* iv)
{
	EVP_CIPHER_CTX *ctx;

	int len;

	if (!(ctx = EVP_CIPHER_CTX_new())) 
		GlobalDF->DebugManager->ThrowError<DCryptException>(nullptr, L"Failed to create Context");

	if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, key->GetKey(), iv))
		GlobalDF->DebugManager->ThrowError<DCryptException>(nullptr, L"Failed to initialize decrypt");

	if (1 != EVP_DecryptUpdate(ctx, Crypt, &len, Origin, OriginLength))
		GlobalDF->DebugManager->ThrowError<DCryptException>(nullptr, L"Failed to update decrypt");
	CryptLength = len;

	if (1 != EVP_DecryptFinal_ex(ctx, Crypt + len, &len))
		GlobalDF->DebugManager->ThrowError<DCryptException>(nullptr, L"Failed to final decrypt");
	CryptLength += len;

	EVP_CIPHER_CTX_free(ctx);
}
