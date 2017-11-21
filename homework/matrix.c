#include<stdio.h>
#include<string.h>
int mat[11][11];
int main()
{
    char op;
    int t,p,q,k,temp;
    memset(mat,0,sizeof(mat));
    scanf(" %d",&t);
    for(p=0;p<t;p++){
        for(q=0;q<t;q++){
            scanf(" %d",&mat[p][q]);
        }
    }
    while(1){
        scanf(" %c",&op);
        if(op=='#') break;
        if(op=='+') k=1;
        if(op=='-') k=-1;
        for(p=0;p<t;p++){
            for(q=0;q<t;q++){
                scanf(" %d",&temp);
                mat[p][q]+=temp*k;
            }
        }
    }
    for(p=0;p<t;p++){
        for(q=0;q<t;q++){
            printf("%5d",mat[p][q]);
        }
        printf("\n");
    }
    return 0;
}
