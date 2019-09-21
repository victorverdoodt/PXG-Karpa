#pragma once
#include <Windows.h>
#include <math.h>

struct Vector
{
	int X, Y, Z;

	inline Vector(void) {}
	inline Vector(const int x, const int y, const int z)
	{
		X = x; Y = y; Z = z;
	}

	inline Vector operator + (const Vector& A) const
	{
		return Vector(X + A.X, Y + A.Y, Z + A.Z);
	}

	inline Vector operator + (const int A) const
	{
		return Vector(X + A, Y + A, Z + A);
	}

	inline Vector operator * (const int A) const
	{
		return Vector(A*X, A*Y, A*Z);
	}

	inline Vector operator * (const Vector& A) const
	{
		return Vector(A.X*X, A.Y*Y, A.Z*Z);
	}

	inline Vector operator - (const int A) const
	{
		return Vector(A*X, A*Y, A*Z);
	}

	inline Vector operator - (const Vector& A) const
	{
		return Vector(A.X - X, A.Y - Y, A.Z - Z);
	}

	inline Vector operator / (const int A) const
	{
		return Vector(A / X, A / Y, A / Z);
	}

	inline Vector operator / (const Vector& A) const
	{
		return Vector(A.X / X, A.Y / Y, A.Z / Z);
	}

	int dot(const Vector &vec) const
	{
		return X * vec.X + Y * vec.Y + Z * vec.Z;
	}

	inline int lengthSquared()
	{
		return X * X + Y * Y + Z * Z;
	}

	inline int length()
	{
		return (int)sqrt(lengthSquared());
	}

	inline Vector perpendicularTo()
	{
		return Vector(Z, Y, -X);
	}

	inline Vector Normalize()
	{
		int length = this->length();
		if (length != 0)
		{
			int inv = 1.0f / length;
			X *= inv;
			Y *= inv;
			Z *= inv;
		}
		return Vector(X, Y, Z);
	}

	inline int DistTo(const Vector& A) {
		int out = sqrtf(powf(X - A.X, 2) + powf(Y - A.Y, 2) + powf(Z - A.Z, 2));
		return out < 0 ? out * -1 : out;
	}

	friend std::ostream & operator<<(std::ostream & _stream, Vector const & mc) {
		return _stream << "(X:"<< mc.X << ", Y:" << mc.Y << ", Z:" << mc.Z << ")"<< std::endl;
	}
};