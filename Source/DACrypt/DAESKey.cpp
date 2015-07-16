#include "stdafx.h"
#include "DAESKey.h"


const unsigned int DCRYPT_AES_KEY_SIZE = 16;

DAESKey::DAESKey()
{
	this->Key = new unsigned char[DCRYPT_AES_KEY_SIZE];
	RAND_pseudo_bytes(this->Key, sizeof(this->Key));
}

DAESKey::DAESKey(unsigned char* key)
	: Key(key)
{
}


DAESKey::~DAESKey()
{
	DDel(this->Key);
}

const unsigned char* DAESKey::GetKey()
{
	return this->Key;
}