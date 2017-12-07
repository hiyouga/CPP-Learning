#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{  
    const char *s="Golden Global View";
    const char *l="ob";
    char *p;
    p=strstr(s,l); 
    printf("%d\n", p-s);
    if (p!=NULL)
    {
        printf("%s\n",p);  
    }
    else  
    {
        printf("Not Found!\n");  
    }
    return 0;  
}  
