#include "stdafx.h"
#include "DIOJSONFileStream.h"

const int DIOJSONFileStream_BufferSize = 65535;

DIOJSONFileReadStream::DIOJSONFileReadStream(const std::string &path)
	: Path(path)
{
}
DIOJSONFileWriteStream::DIOJSONFileWriteStream(const std::string &path)
	: Path(path)
{
}


DIOJSONFileReadStream::~DIOJSONFileReadStream()
{
}
DIOJSONFileWriteStream::~DIOJSONFileWriteStream()
{

}

void DIOJSONFileReadStream::Open()
{
	fp = fopen(this->Path.c_str(), "rb");
}
void DIOJSONFileWriteStream::Open()
{
	fp = fopen(this->Path.c_str(), "wb");
}


void DIOJSONFileReadStream::Close()
{
	fclose(fp);
}
void DIOJSONFileWriteStream::Close()
{
	fclose(fp);
}

rapidjson::Document& DIOJSONFileReadStream::Read()
{
	char readBuffer[DIOJSONFileStream_BufferSize];
	rapidjson::FileReadStream iS(fp, readBuffer, sizeof(readBuffer));
	this->_Document.ParseStream(iS);
	return this->_Document;
}



std::unique_ptr<rapidjson::Writer<rapidjson::FileWriteStream>> DIOJSONFileWriteStream::Write()
{
	char writeBuffer[DIOJSONFileStream_BufferSize];
	rapidjson::FileWriteStream oS(fp, writeBuffer, sizeof(writeBuffer));
	return std::make_unique<rapidjson::Writer<rapidjson::FileWriteStream>>(oS);
}