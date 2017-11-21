#include<stdio.h>
int main()
{
    int n,i,max,min;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    max=min=a[0];
    for(i=1;i<n;i++){
        max=max<a[i]?a[i]:max;
        min=min>a[i]?a[i]:min;
    }
    printf("%d %d\n",max,min);
    return 0;
}
