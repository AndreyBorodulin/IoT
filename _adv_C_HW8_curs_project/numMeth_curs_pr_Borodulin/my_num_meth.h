//#ifndef MY_NUM_METH_H_INCLUDED
//#define MY_NUM_METH_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define EPS1 0.00001 // точность вычисления корней
#define EPS2 0.00001 // точность вычисления интеграла

typedef float(*function)(float);

float f(float x); //задаем функцию 1
float g(float x); //задаем функцию 2
float h(float x); //задаем функцию 3
float df(float x); // производная соответствующей функции
float dg(float x); // производная соответствующей функции
float dh(float x); // производная соответствующей функции
float testf(float x); // тестовая функция
float rootFindLineSearch(float xl, float xr, float eps, function f, function h); // поиск корней линейным перебором
float rootFindTangent(float xn, float eps, function f, function df, function h, function dh); // поиск корней методом касательных (Ньютона)
float calcIntegralSquare(float xl, float xr, size_t n, function f); // поиск интеграла методом прямоугольников
float calcIntegralTrap(float xl, float xr, float eps, function f); // поиск интеграла методом трапеции
void help(void);

//#endif // MY_NUM_METH_H_INCLUDED
