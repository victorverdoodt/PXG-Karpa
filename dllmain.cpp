// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "dllmain.h"
CFunctions Functions;

void attack(DWORD* creature, DWORD ADDR1, DWORD ADDR2) {
	__asm {
		MOV EAX, creature
		push EAX
		MOV ECX, ADDR1
		MOV EDX, 0x4E2540
		CALL EDX
	};
}

CreaturePtr* GetLocalPlayer() {
	return LocalPlayerPointer;
}

double GetLocalPlayerHealth() {
	return ReadMemory<double>((DWORD)LocalPlayerPointer + gHealth);
}

double GetLocalPlayerMaxHealth() {
	return ReadMemory<double>((DWORD)LocalPlayerPointer + gMaxHealth);
}

//On PXG mana = pokemonHealth
double GetLocalPlayerMana() {
	return ReadMemory<double>((DWORD)LocalPlayerPointer + gMana);
}

//On PXG maxMana = pokemonMaxHealth
double GetLocalPlayerMaxMana() {
	return ReadMemory<double>((DWORD)LocalPlayerPointer + gMana);
}

void readBattleList() {
	LocalPlayerPointer = ReadMemory<CreaturePtr*>(baseAddr + gGame);

	std::cout << "LocalPlayer Pointer:"<< LocalPlayerPointer << " Name::" << LocalPlayerPointer->GetName() << ", Health:" << GetLocalPlayerHealth()  << "/" << GetLocalPlayerMaxHealth() <<  "\n";
	//Functions.sendWalkEast((int*)LocalPlayer);
	LocalPlayerPointer->setOutfit(Outfit(0, 168, 125, 78, 200, 123));
	LocalPlayerPointer->SetLight(15);
	auto count = ReadMemory<int>((baseAddr + battleList) + Count);
	std::cout << "Creatures Found:" << count << "\n";
	if (count > 0) {
		auto bufferPointer = ReadMemory<DWORD>((baseAddr + battleList) + BufferPointer);
		auto currentNodeAddress = bufferPointer + NodePointer;

		int i = 1;
		bool stop = false;
		while (!stop) {
			auto nodePointer = ReadMemory<DWORD>(currentNodeAddress);
			if (nodePointer) {
				auto creaturePointer = ReadMemory <CreaturePtr*>(nodePointer + Value);
				if (creaturePointer) {
					if (creaturePointer->isDiff(LocalPlayerPointer)) {
						auto pos = creaturePointer->GetPosition();
						if (creaturePointer->isValid()) {
							//Functions.ForceWalk((int)LocalPlayer, 0, 1);
							std::cout  << "Pointer: " << creaturePointer << ", Health: " << creaturePointer->getHealthPercent() << ", Name:" << creaturePointer->GetName() << ", Pos:" << creaturePointer->GetPosition() << "\n";
						}
					}
				}
			}

			i++;
			if (i <= count) {
				currentNodeAddress = nodePointer + NextPointer;
			}
			else {
				stop = true;
			}
		}

	}
}

void __stdcall Start() {
	Functions.Attack = (Typedefs::Attack)(baseAddr + 0xE2540);
	Functions.ForceWalk = (Typedefs::ForceWalk)(baseAddr + 0xDEA20);
	Functions.sendWalkEast = (Typedefs::sendWalkEast)((DWORD)GetModuleHandle(NULL) + 0x138480);
	//Functions.ForceDisconnect = (Typedefs::ForceDisconnect)(baseAddr + 0xDF650);
	while (true) {
		readBattleList();
		Sleep(1);
	}
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		AllocConsole();
		freopen("CONIN$", "r", stdin);
		freopen("CONOUT$", "w", stdout);

		std::cout << "[+] Successfully attached to process.\n";

		//CreateThread(0, 0, MainThread, hModule, 0, 0);
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Start, 0, 0, 0);
		return TRUE;
		// Alternatively just do easy things here if you dont need an own thread,
		// like patching out things etc...

		break;
	case DLL_THREAD_ATTACH:
		return TRUE;
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}