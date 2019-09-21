#pragma once
#include <Windows.h>

#define baseAddr (DWORD)GetModuleHandle(NULL)


/*local smallBufferSize = 0xE0
	local lengthAddress = address + smallBufferSize
	local length = readInteger(lengthAddress)
	local res = nil
	if (length < smallBufferSize) then
		res = readString(address, length)
	else
		res = readString(readInteger(address), length)
	end
	return res*/
template <class T> T ReadMemory(DWORD dwAddrToRead)
{
	return *(T*)dwAddrToRead;
}

template <class T> bool WriteMemory(DWORD Address, T Valuee)
{
	*(T*)Address = Valuee;
	return true;
}

inline char* GetStr(DWORD offset) {
	auto smallBufferSize = 0xE0;
	auto lengthAddress = offset + smallBufferSize;
	auto length = *(int*)(offset + smallBufferSize);

	if (length < smallBufferSize)
		return (char*)offset;
	else
		return (char*)(*(DWORD*)offset);
}