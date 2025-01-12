
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_num_meth.h"

float f(float x)
{
    return (0.6*x + 3);
}

float g(float x)
{
    return ((x-2)*(x-2)*(x-2) - 1);
}

float h(float x)
{
  return 3/x;
}

float df(float x)
{
   return 0.6;
}

float dg(float x)
{
    return(3*x*x -12*x + 12);
}

float dh(float x)
{
    return (-3/x*x);
}

float testf(float x) // тестовая функция
{
    return 4;
}

// Поиск корней методом линейного перебора
float rootFindLineSearch(float xl, float xr, float eps, function f, function h)
{
    float x, minx = xl, nextstep;
    nextstep = fabs(xr-xl)/(1/eps); //разбиваем на отрезки
    int stepcount=0;
    for(x=xl; x<xr; x += nextstep, stepcount++) {
    if( fabs(f(x) - h(x)) < fabs(f(minx) - h(minx)) )
    minx = x;
    }
    printf("\nFind root for %d steps\n",stepcount); //статистика
    return minx;
}

// поиск корней методом касательных (Ньютона)
float rootFindTangent(float xn, float eps, function f, function df, function h, function dh)
{
    float x1 = xn - ((f(xn) - h(xn))/(df(xn) - dh(xn)));
    float x0 = xn;
    int stepcount = 0;
    while(fabs(x0-x1) > eps)
    {
        x0 = x1;
        x1 = x1 - ((f(x1) - h(x1))/(df(x1) - dh(x1)));
        stepcount++;
    }
    printf("Find Tangent Search root for %d steps\n",stepcount);
    return x1;
}

//поиск интеграла методом прямоугольников
float calcIntegralSquare(float xl, float xr, size_t n, function f)
{
    float sum = 0;
    float h = (xr-xl)/n;
    for(size_t i=0; i<n; i++)
    {
        sum += f(xl);
        xl += h;
    }
    return sum*h;
}

//поиск интеграла методом трапеции
/*float calcIntegralTrap(float xl, float xr, size_t n, function f)
{
    float sum = 0;
    float h = (xr-xl)/n;
    for(float x=xl+h; x<xr-h; x+=h)
    {
        sum += 0.5*h*(f(x)+f(x+h));
    }
    return sum;
}*/

//поиск интеграла методом трапеции с вероятностью в качестве одного из аргументов
float calcIntegralTrap(float xl, float xr, float eps, function f)
{
    float sum = 0;
    float h = eps*(xr-xl);
    for(float x=xl+h; x<xr-h; x+=h)
    {
        sum += 0.5*h*(f(x)+f(x+h));
    }
    return sum;
}


void help(void)
{
    puts("HELLO, FRIEND! Programm is putting out: abscissas of the intersection points\n");
    puts("of the graphs of functions and calculates the areas of figures, which bounded by parts of\n");
    puts("these graphs at their intersection!\n");
    printf("In this program release we have the parameters of command line:\n");
    //puts("\n-help :See HELP;");
}





