#pragma once
class DAESKey :
	public DObject
{
	DClass(DAESKey)
private:
	unsigned char* Key;
public:
	DAESKey();
	DAESKey(unsigned char* key);
	~DAESKey();

	const unsigned char* GetKey();
};

