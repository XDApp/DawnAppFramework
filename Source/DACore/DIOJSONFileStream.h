#pragma once
#include "DIOStream.h"
class DIOJSONFileReadStream :
	public DIOStream
{
	DClass(DIOJSONFileReadStream)
private:
	rapidjson::Document _Document;
	const std::string Path;

	FILE* fp;
public:
	DIOJSONFileReadStream(const std::string &path);
	~DIOJSONFileReadStream();

	virtual void Open() override;
	virtual void Close()  override;
	virtual void Buffer() override;

	rapidjson::Document& Read();
};

class DIOJSONFileWriteStream :
	public DIOStream
{
	DClass(DIOJSONFileWriteStream)
private:
	const std::string Path;

	FILE* fp;
public:
	DIOJSONFileWriteStream(const std::string &path);
	~DIOJSONFileWriteStream();

	virtual void Open() override;
	virtual void Close()  override;
	virtual void Buffer() override;

	std::unique_ptr<rapidjson::Writer<rapidjson::FileWriteStream>> Write();
};

