// DawnAppFramework.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <DACore/DObject.h>
#include <DACore/DReference.h>
class DManager : public DObject {
	DManager() : DObject() {
		this->DF->PullReference(this);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

