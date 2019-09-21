#pragma once
//gMap
#define gMap 0x3BC560
#define knownCreatures 0x1C0
#define gGame 0x3BC320


#define battleList gMap + knownCreatures
//UnorderedMapOffsets
#define Unknown 0x0
#define BufferPointer 0x8
#define Count 0xC

//UnorderedMapBufferOffsets
#define NodePointer 0x0

//UnorderedMapNodeOffsets
#define	NextPointer 0x0
#define	PreviousPointer 0x4
#define	Key 0x8
#define	Value 0x8

//Functions
#define cAttack 0xE2540//0x13ADA0


//LocalPlayer offset
#define gHealth 0x390
#define gMaxHealth 0x398
#define gMana 0x3C8
#define gMaxMana 0x3D0

//Creatures Blist OffSets
#define cHealth 0x38
#define cPosX 0xC
#define cPosY 0x10
#define cPosZ 0x14
#define cId 0x1C
#define cName 0x28
#define cDir 0x3C


