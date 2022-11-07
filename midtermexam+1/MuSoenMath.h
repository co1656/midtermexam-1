#pragma once
#include <iostream>
using namespace std;

class mat3
{
public: //외부에서 접근 가능하도록
	float mat[3][3];

	float mat(float a, float b, float c, float d, float e, float f, float g, float h, float i)
	{
		mat[0][0] = a;
		mat[0][1] = b;
		mat[0][2] = c;
		mat[1][0] = d;
		mat[1][1] = e;
		mat[1][2] = f;
		mat[2][0] = g;
		mat[2][1] = h;
		mat[2][2] = i;
	}
};

class vec3
{
public: //외부에서 접근 가능하도록
	float x, y, z;

	float vec[3] = { x,y,z}; //2차원배열 생성

	float vec()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	float vec(float x1, float y1, float z1)
	{
		x = x1;
		y = y1;
		z = z1;
	}
};

const vec3 operator * (const vec3&vec, const mat3&mm) //행렬 곱셈 계산
{
	vec3 vv;
	mat3 ma = mm;

	vv.x = ma.mat[0][0] * vec.x + ma.mat[0][1] * vec.y + ma.mat[0][2] * vec.z;
	vv.y = ma.mat[1][0] * vec.x + ma.mat[1][1] * vec.y + ma.mat[1][2] * vec.z;
	vv.z = ma.mat[2][0] * vec.x + ma.mat[2][1] * vec.y + ma.mat[2][2] * vec.z;

	return vv;
}

void matrix()
{
	vec3 v(1,1,1);

	mat3 T[3][3] = {1, 0, 0, //x로 3, y로 5 이동
		0, 1, 0,
		3, 5, 1};

	mat3 R[3][3] = {cos(3.14 / 6), -sin(3.14 / 6), 0, //30도 회전
		sin(3.14 / 6), cos(3.14 / 6), 0,
		0, 0, 1};

	mat3 S[3][3] = {2, 0, 0, //크기 2배 증가
		0, 2, 0,
		0, 0, 1};

	vec3 p = v * T * R * S; //연산

		cout << p << endl; //결과값 출력
}
