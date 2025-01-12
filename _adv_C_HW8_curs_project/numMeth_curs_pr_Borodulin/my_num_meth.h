//#ifndef MY_NUM_METH_H_INCLUDED
//#define MY_NUM_METH_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define EPS1 0.00001 // �������� ���������� ������
#define EPS2 0.00001 // �������� ���������� ���������

typedef float(*function)(float);

float f(float x); //������ ������� 1
float g(float x); //������ ������� 2
float h(float x); //������ ������� 3
float df(float x); // ����������� ��������������� �������
float dg(float x); // ����������� ��������������� �������
float dh(float x); // ����������� ��������������� �������
float testf(float x); // �������� �������
float rootFindLineSearch(float xl, float xr, float eps, function f, function h); // ����� ������ �������� ���������
float rootFindTangent(float xn, float eps, function f, function df, function h, function dh); // ����� ������ ������� ����������� (�������)
float calcIntegralSquare(float xl, float xr, size_t n, function f); // ����� ��������� ������� ���������������
float calcIntegralTrap(float xl, float xr, float eps, function f); // ����� ��������� ������� ��������
void help(void);

//#endif // MY_NUM_METH_H_INCLUDED
