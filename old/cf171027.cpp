#include<cstdio>//stdio.h in c
int main()
{
    int year;
    scanf("%d",&year);
    if((year%4==0&&year%100!=0)||(year%400==0)){
        printf("%d is run\n",year);
    }else{
        printf("%d isn't \n",year);
    }
    return 0;
}
