#include<stdio.h>
int main()
{
    int a[100],b[100],p,q,f,r,s;
    scanf("%d",&a[0]);
    for(p=0;a[p]!=-1;p++){
        scanf("%d",&a[p+1]);
    }
    scanf("%d",&b[0]);
    for(q=0;b[q]!=-1;q++){
        scanf("%d",&b[q+1]);
    }
    for(r=0;r<p;r++){
        f=0;
        for(s=0;s<q;s++){
            if(a[r]==b[s]) f++;
        }
        if(!f) printf("%d ",a[r]);
    }
    return 0;
}
