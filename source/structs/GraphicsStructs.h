#pragma once

struct mat4f;
struct vec3f;

//3D Vector
struct vec3f
{
	float x, y, z;

	//vector arithmetic
	vec3f operator+(vec3f i)
	{
		return vec3f{ x + i.x,y + i.y,z + i.z };
	}
	vec3f operator-(vec3f i)
	{
		return vec3f{ x - i.x,y - i.y,z - i.z };
	}
	vec3f operator*(vec3f i)
	{
		return vec3f{ x * i.x,y * i.y,z * i.z };
	}
	vec3f operator/(vec3f i)
	{
		return vec3f{ x / i.x,y / i.y,z / i.z };
	}

	//scalar arithmetic
	vec3f operator+(float i)
	{
		return vec3f{ x + i,y + i,z + i };
	}
	vec3f operator-(float i)
	{
		return vec3f{ x - i,y - i,z - i };
	}
	vec3f operator*(float i)
	{
		return vec3f{ x * i,y * i,z * i };
	}
	vec3f operator/(float i)
	{
		return vec3f{ x / i,y / i,z / i };
	}

};

//4x4 Matrix
struct mat4f
{
	float c[4][4];
};
