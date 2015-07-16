#pragma once

class DAESKey;

class DCryptAES
{
public:
	DCryptAES();
	virtual ~DCryptAES();

	static void AES_Encrypt(DAESKey *key, unsigned char* &Crypt, size_t &CryptLength, const unsigned char* Origin, const size_t OriginLength, const unsigned char* iv);
	static void AES_Decrypt(DAESKey *key, unsigned char* &Crypt, size_t &CryptLength, const unsigned char* Origin, const size_t OriginLength, const unsigned char* iv);
};

