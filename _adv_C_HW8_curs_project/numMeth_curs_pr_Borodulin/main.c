/*�������� ������ �� ����� "����������� ��". ������ � ��������� ��������.
��������� �������� ���������� ����������� � ������������� ��������� � �� ��������� ������.
��� ������� ��� �������� ������, ��������� ������ ������� ���������� � ����� ���������� �
��������� ��� ����� ������ ��������� ������ ��� ���������� ����������.
�����: ��������� �.�.
���_����_��� �01-111
2024 �.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "my_num_meth.h"

int main(int argc, char *argv[])
{

   double x_D, x_B, x_E; // �������� ����� ����������� �������� ������� (�����)
   double S_1, S_2, S_3, S__D_E_B = 0; // ������� (������� ����������)

   if (argc == 1 || (argc > 1 && strcmp(argv[1], "-help") == 0))
    {
        help(); // �����������
        puts("-help : What we can do!");
        puts("-crossing : find roots and number of search iterations");
        puts("-integral : find area (integral) what we need");
        puts("-test : checking the program's operation on a simple test function");
        return 0;
    }

    if (strcmp(argv[1], "-crossing") == 0)
    {
      puts("The less accurate method for TESTING:\n");
      printf("Line Search root_point_D = %f\n",rootFindLineSearch(0.5,1,0.001,f, h));
      printf("Line Search root_point_B = %f\n",rootFindLineSearch(3.0,3.5,0.001,g, h));
      printf("Line Search root_point_E = %f\n\n\n",rootFindLineSearch(3.6,4.5,0.001,f, g));

      puts("The More accurate method:\n");
      printf("NewTon root_point_D = %f\n\n", x_D = rootFindTangent(0.5, EPS1, f, df, h, dh));
      printf("NewTon root_point_B = %f\n\n", x_B = rootFindTangent(3.0, EPS1, g, dg, h, dh));
      printf("NewTon root_point_E = %f\n\n", x_E = rootFindTangent(3.6, EPS1, g, dg, f, df));
      return 0;
    }

    if (strcmp(argv[1], "-integral") == 0)
    {

        x_D = rootFindTangent(0.5, EPS1, f, df, h, dh);
        x_B = rootFindTangent(3.0, EPS1, g, dg, h, dh);
        x_E = rootFindTangent(3.6, EPS1, g, dg, f, df);

        puts("\nThe less accurate method:\n");
        S_1 = calcIntegralSquare(x_D,x_E,10000,f); // Square S_f(x) under D-E
        S_2 = calcIntegralSquare(x_D,x_B,10000,h); // Square S_h(x) under D-B
        S_3 = calcIntegralSquare(x_B,x_E,10000,g); // Square S_g(x) under B-E
        printf("Integral by Method of Square S__D_E_B = %f\n\n",S__D_E_B = S_1 - S_2 - S_3); // ������� ������� ������ (��. �����)

        puts("The More accurate method:\n");
        S_1 = calcIntegralTrap(x_D,x_E,EPS2,f); // Trap S_f(x) under D-E
        S_2 = calcIntegralTrap(x_D,x_B,EPS2,h); // Trap S_h(x) under D-B
        S_3 = calcIntegralTrap(x_B,x_E,EPS2,g); // Trap S_g(x) under B-E
        printf("Integral by Method of Trap S__D_E_B = %f\n",S__D_E_B = S_1 - S_2 - S_3);
        return 0;
    }

    if (strcmp(argv[1], "-test") == 0)
    {
        printf("calcIntegralSquare integral TEST for 4*4 - %f\n",calcIntegralSquare(0,4,1000,testf));
        printf("calcIntegralTrap integral TEST for 4*4 - %f\n",calcIntegralTrap(0,4,EPS2,testf));
        return 0;
    }

   printf("UNKNOWN KEY, TRY -help");
   return 0;
}










