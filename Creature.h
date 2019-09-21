#include "Offsets.h"
#include "Vector.h"
#include "Utils.h"
#include "Outfit.h"
#include "dllmain.h"
//Creature BattleList Data Struct / Functions

class CreaturePtr
{
//Data Functions
public:
	//is local player
	bool isDiff(CreaturePtr * p) {
		if (this != p)
			return true;

		return false;
	}

	bool isValid() {
		if (this->PosX < 65535 && this->PosX > 0 && this->PosZ < 255)
			return true;

		return false;
	}

	//Get Creature Position Vector
	Vector GetPosition() {
		return Vector(this->PosX, this->PosY, this->PosZ);
	}

	//Get Creature Name
	char* GetName() {
		if (this->NameLenght > 16) {
			return ReadMemory<char*>((DWORD)this->Name);
		}
		return this->Name;
	}

	//Get Health Bar Percent
	int16_t getHealthPercent() {
		int H = this->Health;
		if (H > 100)
			return -1;
		return H;
	}

	//Get Look Direction
	int16_t GetLookDirection() {
		return this->Dir;
	}

	//Set Creature Look Direction
	void SetLookDirection(int dir){ 
		this->Dir = dir;
	}

	//Get Creature Id
	int16_t GetId() {
		this->Id;
	}

	//Get Creature Outfit Struct
	Outfit getOutfit() {
		return Outfit(this->Addon, this->LookType, this->Head, this->Body, this->Legs, this->Feet);
	}

	//Set Creature Outfit Struct
	void setOutfit(Outfit outfit) {
		this->LookType = outfit.LookType; this->Head = outfit.Head; this->Body = outfit.Body; this->Legs = outfit.Legs; this->Feet = outfit.Feet;
	}

	//Get Creature Light
	int16_t GetLight() {
		return this->Light;
	}

	//Set Creature Light
	void SetLight(int light) {
		this->Light = light;
	}

	//Get CreatureSpeed
	int16_t GetSpeed() {
		return this->Speed;
	}

	//Set Creature Speed
	void SetSpeed(int speed) {
		this->Speed = speed;
	}

//Creature Data Structure Missing Light Color and Id possible wrong
private:
	char pad_0000[12]; //0x0000
	int16_t PosX; //0x000C
	char pad_000E[2]; //0x000E
	int16_t PosY; //0x0010
	char pad_0012[2]; //0x0012
	int16_t PosZ; //0x0014
	char pad_0016[6]; //0x0016
	int16_t Id; //0x001C
	char pad_001E[6]; //0x001E
	int16_t NameLenght; //0x0024
	char pad_0026[2]; //0x0026
	char Name[16]; //0x0028
	int16_t Health; //0x0038
	char pad_003A[2]; //0x003A
	int16_t Dir; //0x003C
	char pad_003E[2]; //0x003E
	int16_t Addon; //0x0040
	char pad_0042[2]; //0x0042
	int16_t LookType; //0x0044
	char pad_0046[6]; //0x0046
	int16_t Head; //0x004C
	char pad_004E[2]; //0x004E
	int16_t Body; //0x0050
	char pad_0052[2]; //0x0052
	int16_t Legs; //0x0054
	char pad_0056[2]; //0x0056
	int16_t Feet; //0x0058
	char pad_005A[86]; //0x005A
	int16_t Light; //0x00B0
	char pad_00B2[2]; //0x00B2
	int16_t Speed; //0x00B4
}; //Size: 0x00B6