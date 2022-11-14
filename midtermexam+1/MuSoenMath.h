#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class mat4//4*4���
{
public: //�ܺο��� ���� �����ϵ���
	float mat[4][4];

	mat4() { //  ��� ������
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				mat[i][j] = 0; // ��� ���� �ʱ�ȭ
			}
		}
	}

	mat4(float a1, float b1, float c1, float d1, float e1, float f1, float g1, float h1, float i1, float j1, float k1, float l1 ,float m1, float n1, float o1, float p1)
	{
		mat[0][0] = a1;
		mat[0][1] = b1;
		mat[0][2] = c1;
		mat[0][3] = d1;
		mat[1][0] = e1;
		mat[1][1] = f1;
		mat[1][2] = g1;
		mat[1][3] = h1;
		mat[2][0] = i1;
		mat[2][1] = j1;
		mat[2][2] = k1;
		mat[2][3] = l1;
		mat[3][0] = m1;
		mat[3][1] = n1;
		mat[3][2] = o1;
		mat[3][3] = p1;
	}

	mat4 identity_matrix()//�������
	{
		return mat4(
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1);
	}

	mat4 transpose_matrix() //��ġ��ķ� ��ȯ
	{
		mat4 mm4;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				mm4.mat[i][j] = mat[j][i];
			}
		}
		return mm4;
	}
};

class mat3//3*3���
{
public: //�ܺο��� ���� �����ϵ���
	float mat[3][3];

	mat3() { //  ��� ������
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				mat[i][j] = 0; // ��� ���� �ʱ�ȭ
			}
		}
	}

	mat3(float a, float b, float c, float d, float e, float f, float g, float h, float i)
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

	mat3 identity_matrix()//�������
	{
		return mat3(
			1, 0, 0,
			0, 1, 0,
			0, 0, 1);
	}

	mat3 transpose_matrix() //��ġ��ķ� ��ȯ
	{
		mat3 mm;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				mm.mat[i][j] = mat[j][i];
			}
		}
		return mm;
	}
};

class vec3 //3*1
{
public: //�ܺ����ٰ���
	float x, y, z;

	float vec[3] = {x,y,z}; //2�����迭 ����

	vec3() //�ʱ�迭
	{
		x = 0;
		y = 0;
		z = 1;
	}

	vec3(float x1, float y1, float z1)
	{
		x = x1;
		y = y1;
		z = z1;
	}
};

class vec1x3 //1*3
{
public: //�ܺ����ٰ���

	float vec[1][3]; //2�����迭 ����

	vec1x3() //�迭 �ʱ�ȭ
	{
		vec[0][0] = 0;
		vec[1][0] = 0;
		vec[2][0] = 1;
	}

	vec1x3(float x2, float y2, float z2)
	{
		vec[0][0] = x2;
		vec[1][0] = y2;
		vec[2][0] = z2;
	}
};

class vec1x4 //1*3
{
public: //�ܺ����ٰ���

	float vec[1][4]; //2�����迭 ����

	vec1x4() //�迭 �ʱ�ȭ
	{
		vec[0][0] = 0;
		vec[1][0] = 0;
		vec[2][0] = 0;
		vec[3][0] = 1;
	}

	vec1x4(float x3, float y3, float z3, float w3)
	{
		vec[0][0] = x3;
		vec[1][0] = y3;
		vec[2][0] = z3;
		vec[3][0] = w3;
	}
};

class vec4 //3*1
{
public: //�ܺ����ٰ���
	float x, y, z,w;

	float vec[4] = { x,y,z,w }; //2�����迭 ����

	vec4() //�ʱ�迭
	{
		x = 0;
		y = 0;
		z = 0;
		w = 1;
	}

	vec4(float x4, float y4, float z4, float w4)
	{
		x = x4;
		y = y4;
		z = z4;
		w = w4;
	}
};

const vec3 operator * (const vec3 vec, const mat3 mm) //31����,33��� ���� ���
{
	vec3 vv;
	mat3 ma = mm;

	vv.x = ma.mat[0][0] * vec.x + ma.mat[1][0] * vec.y + ma.mat[2][0] * vec.z;
	vv.y = ma.mat[0][1] * vec.x + ma.mat[1][1] * vec.y + ma.mat[2][1] * vec.z;
	vv.z = ma.mat[0][2] * vec.x + ma.mat[1][2] * vec.y + ma.mat[2][2] * vec.z;

	return vv;
}

const mat3 operator * (const mat3& mb, const mat3& mc) //33��� ���� ���
{
	mat3 m1;
	mat3 m2 = mc;

	m1.mat[0][0] = m1.mat[0][0] * m2.mat[0][0] + m1.mat[0][0] * m2.mat[1][0] + m1.mat[0][0] * m2.mat[2][0];
	m1.mat[1][1] = m1.mat[1][1] * m2.mat[0][1] + m1.mat[1][1] * m2.mat[1][1] + m1.mat[1][1] * m2.mat[2][1];
	m1.mat[2][2] = m1.mat[2][2] * m2.mat[0][2] + m1.mat[2][2] * m2.mat[1][2] + m1.mat[2][2] * m2.mat[2][2];

	return m1;
}

const vec4 operator * (const vec4 vec, const mat4 mm4) //41����,44��� ���� ���
{
	vec4 v4;
	mat4 m4 = mm4;

	v4.x = m4.mat[0][0] * vec.x + m4.mat[1][0] * vec.y + m4.mat[2][0] * vec.z + m4.mat[3][0] * vec.w;
	v4.y = m4.mat[0][1] * vec.x + m4.mat[1][1] * vec.y + m4.mat[2][1] * vec.z + m4.mat[3][1] * vec.w;
	v4.z = m4.mat[0][2] * vec.x + m4.mat[1][2] * vec.y + m4.mat[2][2] * vec.z + m4.mat[3][2] * vec.w;
	v4.w = m4.mat[0][3] * vec.x + m4.mat[1][3] * vec.y + m4.mat[2][3] * vec.z + m4.mat[3][3] * vec.w;

	return v4;
}

const mat4 operator * (const mat4& mb, const mat4& mc4) //44��� ���� ���
{
	mat4 m41;
	mat4 m42 = mc4;

	m41.mat[0][0] = m41.mat[0][0] * m42.mat[0][0] + m41.mat[0][0] * m42.mat[1][0] + m41.mat[0][0] * m42.mat[2][0] + m41.mat[0][0] * m42.mat[3][0];
	m41.mat[1][1] = m41.mat[1][1] * m42.mat[0][1] + m41.mat[1][1] * m42.mat[1][1] + m41.mat[1][1] * m42.mat[2][1] + m41.mat[1][1] * m42.mat[3][1];;
	m41.mat[2][2] = m41.mat[2][2] * m42.mat[0][2] + m41.mat[0][0] * m42.mat[1][2] + m41.mat[0][0] * m42.mat[2][2] + m41.mat[2][2] * m42.mat[3][2];;
	m41.mat[3][3] = m41.mat[3][3] * m42.mat[0][2] + m41.mat[0][0] * m42.mat[1][2] + m41.mat[0][0] * m42.mat[2][2] + m41.mat[3][3] * m42.mat[3][3];;

	return m41;
}

void matrix()
{
	vec3 v(1,1,1);

	mat3 T= mat3(1, 0, 0, //x�� 3, y�� 5 �̵�
		0, 1, 0,
		3, 5, 1);

	mat3 R= mat3(cos(3.14 / 6), -sin(3.14 / 6), 0, //30�� ȸ��
		sin(3.14 / 6), cos(3.14 / 6), 0,
		0, 0, 1);

	mat3 S= mat3(2, 0, 0, //ũ�� 2�� ����
		0, 2, 0,
		0, 0, 1);

	vec3 p = v * T * R * S; //����

	cout << p.x << ", " << p.y << ", " << p.z << endl; //����� ���
}
