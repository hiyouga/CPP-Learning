#include<stdio.h>

void main()
{
   char *language[] = {"FORTRAN", "BASIC", "PASCAL", "JAVA", "C"};
   printf("%d", *(language+2));
}
