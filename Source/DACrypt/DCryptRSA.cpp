#include "stdafx.h"
#include "DCryptRSA.h"
#include "DCryptException.h"
#include "DRSAKey.h"

DCryptRSA::DCryptRSA()
{
}

DCryptRSA::~DCryptRSA()
{
}

EVP_PKEY *DCryptRSA::ToEVP(RSA *rsaKey)
{
	EVP_PKEY* pKey = EVP_PKEY_new();
	if (!pKey)
	{
		GlobalDF->DebugManager->ThrowError<DCryptException>(nullptr, L"Failed to create EVP Key");
		return nullptr;
	}
	EVP_PKEY_assign_RSA(pKey, rsaKey);
	return pKey;
}

void DCryptRSA::Initialize()
{
	ERR_load_crypto_strings();
	OpenSSL_add_all_algorithms();
	OpenSSL_add_all_ciphers();
}

void DCryptRSA::Dispose()
{
	EVP_cleanup();
	CRYPTO_cleanup_all_ex_data();

	ERR_free_strings();
}

void DCryptRSA::EVP_Encrypt(EVP_PKEY *key, unsigned char* Crypt, size_t &CryptLength, const unsigned char* Origin, const size_t OriginLength)
{
	EVP_PKEY_CTX *ctx;
	ENGINE *eng = nullptr;

	ctx = EVP_PKEY_CTX_new(key, eng);
	if (!ctx)
		GlobalDF->DebugManager->ThrowError<DCryptException>(nullptr, L"Failed to open Context");
	if (EVP_PKEY_encrypt_init(ctx) <= 0)
		GlobalDF->DebugManager->ThrowError<DCryptException>(nullptr, L"Failed to initialize Context");
	if (EVP_PKEY_CTX_set_rsa_padding(ctx, RSA_PKCS1_PADDING) <= 0)
		GlobalDF->DebugManager->ThrowError<DCryptException>(nullptr, L"Failed to set padding");
	if (EVP_PKEY_encrypt(ctx, nullptr, &CryptLength, Origin, OriginLength) <= 0)
		GlobalDF->DebugManager->ThrowError<DCryptException>(nullptr, L"Failed to check buffer");
	if (EVP_PKEY_encrypt(ctx, Crypt, &CryptLength, Origin, OriginLength) <= 0)
	{
		ERR_print_errors_fp(stderr);
		GlobalDF->DebugManager->ThrowError<DCryptException>(nullptr, L"Failed to encrypt");
	}
		
	EVP_cleanup();
}

void DCryptRSA::EVP_Decrypt(EVP_PKEY *key, unsigned char* Crypt, size_t &CryptLength, const unsigned char* Origin, const size_t OriginLength)
{
	EVP_PKEY_CTX *ctx;
	ENGINE *eng = nullptr;

	ctx = EVP_PKEY_CTX_new(key, eng);
	if (!ctx)
		GlobalDF->DebugManager->ThrowError<DCryptException>(nullptr, L"Failed to open Context");
	if (EVP_PKEY_decrypt_init(ctx) <= 0)
		GlobalDF->DebugManager->ThrowError<DCryptException>(nullptr, L"Failed to initialize Context");
	if (EVP_PKEY_CTX_set_rsa_padding(ctx, RSA_PKCS1_PADDING) <= 0)
		GlobalDF->DebugManager->ThrowError<DCryptException>(nullptr, L"Failed to set padding");
	if (EVP_PKEY_decrypt(ctx, nullptr, &CryptLength, Origin, OriginLength) <= 0)
		GlobalDF->DebugManager->ThrowError<DCryptException>(nullptr, L"Failed to check buffer");
	Crypt =(unsigned char*) OPENSSL_malloc(CryptLength);
	if (EVP_PKEY_decrypt(ctx, Crypt, &CryptLength, Origin, OriginLength) <= 0)
	{
		ERR_print_errors_fp(stderr);
		GlobalDF->DebugManager->ThrowError<DCryptException>(nullptr, L"Failed to encrypt");
	}
}
const int DCRYPTRSA_PADDING = RSA_PKCS1_OAEP_PADDING;

void DCryptRSA::RSA_Encrypt(RSA *key, unsigned char* Crypt, size_t &CryptLength, const unsigned char* Origin, const size_t OriginLength)
{
	CryptLength = RSA_public_encrypt(OriginLength, Origin, Crypt, key, DCRYPTRSA_PADDING);
}

void DCryptRSA::RSA_Decrypt(RSA *key, unsigned char* Crypt, size_t &CryptLength, const unsigned char* Origin, const size_t OriginLength)
{
	CryptLength = RSA_private_decrypt(OriginLength, Origin, Crypt, key, DCRYPTRSA_PADDING);
}

