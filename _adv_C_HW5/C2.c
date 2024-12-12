//C2 �������� �������� ������


#include <stdio.h>
 int main()
 {
     int stack[1000];
     // sp = ������ ������, ���� ����� push-����� ��������� �����
     int sp =0;      // (sp-1) = ������ ������, ���������� �������� �����
     while ( !feof(stdin) ) {
         int c = getchar();
         int x;
         switch (c) {
             case  ' ':
             case '\n':
                 break;
             case '.':
                 printf("%d", stack[sp - 1]);  sp--;
                 return 0;
             case '+':
                stack[sp-2] = stack[sp-2] + stack[sp-1];  sp--;
                break;
             case '-':
                stack[sp-2] = stack[sp-2] - stack[sp-1];  sp--;
                break;
             case '*':
                stack[sp-2] = stack[sp-1] * stack[sp-2];  sp--;
                break;
             case '/':
               stack[sp-2] = stack[sp-2] / stack[sp-1];   sp--;
                break;
             default:
                 ungetc (c, stdin); // ������� ������ ������� � �����
                 if (scanf("%d", &x) != 1) {
                     fprintf(stderr, "Can't read integer\n");
                     return -1;
                 } else {
                     stack[sp] = x; sp++;
                 }
         }
     }
     return 0;
 }
