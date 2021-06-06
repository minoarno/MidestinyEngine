#include "MiniginPCH.h"
#include "BinaryWriter.h"
#include "Log.h"

void BinaryWriter::SaveToBin(std::ofstream& out, float f)
{
	if (out.is_open())
	{
		SaveToBin(out, DataType::f);
		out.write((const char*)&f, sizeof(f));
	}
	else
	{
		ME_CORE_WARN("the output stream is not open");
	}
}

void BinaryWriter::SaveToBin(std::ofstream& out, const std::string& s)
{
	if (out.is_open())
	{
		DataType dataType{ DataType::s };
		out.write((const char*)&dataType, sizeof(DataType)); // basically saying it's a string
		int size{ int(s.size()) };
		out.write((const char*)&size, sizeof(int)); //length
		//const char* cString{ s.c_str() };
		out.write((const char*)s.c_str(), size); // string
	}
	else
	{
		ME_CORE_WARN("the output stream is not open");
	}
}

void BinaryWriter::SaveToBin(std::ofstream& out, int i)
{
	if (out.is_open())
	{
		SaveToBin(out, DataType::i);
		out.write((const char*)&i, sizeof(i));
	}
	else
	{
		ME_CORE_WARN("the output stream is not open");
	}
}

void BinaryWriter::SaveToBin(std::ofstream& out, DataType d)
{
	int i{ int(d) };
	if (out.is_open())
	{
		out.write((const char*)&i, sizeof(i));
	}
	else
	{
		ME_CORE_WARN("the output stream is not open");
	}
}
