#pragma once

#include <cmath>

struct vec
{
	float x;
	float y;
	float z;
};

inline float dot(vec a, vec b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline vec operator/(vec a, float b)
{
	return vec{ a.x / b, a.y / b, a.z / b };
}

inline vec operator-(vec a, vec b)
{
	return vec{a.x - b.x, a.y - b.y, a.z - b.z};
}

inline float magnitude(vec a)
{
	return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);;
}

inline vec normalize(vec a)
{
	const float mag = magnitude(a);
	return a / mag;
}