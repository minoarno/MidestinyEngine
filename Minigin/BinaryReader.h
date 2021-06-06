#pragma once
#include <fstream>
#include "BinaryDataType.h"

namespace BinaryReader
{
	float ReadFloatFromBin(std::ifstream& in);
	std::string ReadStringFromBin(std::ifstream& in);
	int ReadIntFromBin(std::ifstream& in);
	DataType ReadDataTypeFromBin(std::ifstream& in);
};

