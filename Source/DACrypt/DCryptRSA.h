#pragma once

class DRSAKey;
class DCryptRSA
{
public:
	DCryptRSA();
	virtual ~DCryptRSA() = 0;

	static EVP_PKEY *ToEVP(RSA *rsaKey);
	static void Initialize();
	static void Dispose();

	static void EVP_Encrypt(EVP_PKEY *key, unsigned char* Crypt, size_t &CryptLength, const unsigned char* Origin, const size_t OriginLength);
	static void EVP_Decrypt(EVP_PKEY *key, unsigned char* Crypt, size_t &CryptLength, const unsigned char* Origin, const size_t OriginLength);
	static void RSA_Encrypt(RSA *key, unsigned char* Crypt, size_t &CryptLength, const unsigned char* Origin, const size_t OriginLength);
	static void RSA_Decrypt(RSA *key, unsigned char* Crypt, size_t &CryptLength, const unsigned char* Origin, const size_t OriginLength);
};
