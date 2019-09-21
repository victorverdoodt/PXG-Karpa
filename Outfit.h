#pragma once
struct Outfit
{
public:
	int Addon, LookType, Head, Body, Legs, Feet;
	inline Outfit(void) {}
	inline Outfit(const int addon, const int looktype, const int head, const int body, const int legs, const int feet)
	{
		Addon = addon; LookType = looktype; Head = head; Body = body; Legs = legs; Feet = feet;
	}
};