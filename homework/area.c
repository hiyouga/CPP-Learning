#include<stdio.h>
int main()
{
    int p,x[4],y[4],sx,sy;//a1 a2 b1 b2
    for(p=0;p<4;p++){
        scanf("%d %d",&x[p],&y[p]);
    }
    int mx[6],my[6];
    //0 max_a 1 min_a
    //2 max_b 3 min_b
    //4 max_in_min 5 min_in_max
    mx[0]=x[0]>x[1]?x[0]:x[1];
    mx[1]=x[0]<x[1]?x[0]:x[1];
    mx[2]=x[2]>x[3]?x[2]:x[3];
    mx[3]=x[2]<x[3]?x[2]:x[3];
    my[0]=y[0]>y[1]?y[0]:y[1];
    my[1]=y[0]<y[1]?y[0]:y[1];
    my[2]=y[2]>y[3]?y[2]:y[3];
    my[3]=y[2]<y[3]?y[2]:y[3];
    mx[4]=mx[1]>mx[3]?mx[1]:mx[3];
    mx[5]=mx[0]<mx[2]?mx[0]:mx[2];
    my[4]=my[1]>my[3]?my[1]:my[3];
    my[5]=my[0]<my[2]?my[0]:my[2];
    if(mx[5]>mx[4]){
        sx=mx[5]-mx[4];
    }else{
        sx=0;
    }
    if(my[5]>my[4]){
        sy=my[5]-my[4];
    }else{
        sy=0;
    }
    printf("%d\n",sx*sy);
    return 0;
}
