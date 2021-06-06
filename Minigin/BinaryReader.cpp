#include "MiniginPCH.h"
#include "BinaryReader.h"
#include "Log.h"

float BinaryReader::ReadFloatFromBin(std::ifstream& in)
{
	float f{ 0 };

	if constexpr (std::is_pod<float>::value == 1)
	{

		if (in.is_open())
		{
			in.read((char*)&f, sizeof(f));
		}
		else
		{
			ME_CORE_WARN("the input file can't be opened");
		}
	}
	return f;
}

std::string BinaryReader::ReadStringFromBin(std::ifstream& in)
{
	std::string s{ "" };
	if constexpr (std::is_pod<char*>::value == 1)
	{
		if (in.is_open())
		{
			int length{};
			in.read((char*)&length, sizeof(int));
			char* temp = new char[length];
			in.read((char*)temp, length);
			s.append(temp, length);
		}
		else
		{
			ME_CORE_WARN("the input file can't be opened");
		}
	}
	return s;
}

int BinaryReader::ReadIntFromBin(std::ifstream& in)
{
	int i{ 0 };
	if constexpr(std::is_pod<int> ::value == 1)
	{
		if (in.is_open())
		{
			in.read((char*)&i, sizeof(int));
		}
		else
		{
			ME_CORE_WARN("the input file can't be opened");
		}
	}
	return i;
}

DataType BinaryReader::ReadDataTypeFromBin(std::ifstream& in)
{
	return DataType(ReadIntFromBin(in));
}
