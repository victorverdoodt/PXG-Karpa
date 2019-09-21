class Typedefs{
public:
	typedef  void(__thiscall* Attack)(DWORD *a1, int a2, DWORD **a3);
	typedef int (__fastcall* ForceDisconnect)(int a1);
	typedef void (__fastcall* ForceWalk)(int P, int a1, int Dir);
	typedef void* (__thiscall* sendWalkEast)(int *a1);
	typedef void (__fastcall* sub_538780)(int *a1);
};

class CFunctions {
public:
	Typedefs::Attack Attack;
	Typedefs::ForceDisconnect ForceDisconnect;
	Typedefs::ForceWalk ForceWalk;
	Typedefs::sendWalkEast sendWalkEast;
};

extern CFunctions Functions;