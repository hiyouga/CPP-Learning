/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 361296
 Created at: Mon Oct 30 2017 00:47:30 GMT+0800 (CST)
 Problem_id: 170	Time: 2	Memory: 1492
*/

#include<cstdio>
int k=0;
void chs(char sb[8][8],int ro,int co,int n,int x,int y)
{
    if(x+ro>=0&&x+ro<=7&&y+co>=0&&y+co<=7)
    {
        if(sb[x+ro][y+co]=='D'){
            k+=n;}
        else if(sb[x+ro][y+co]=='L'){chs(sb,ro,co,n+1,x+ro,y+co);}
    }
}
main()
{
    int n;
    ~scanf("%d",&n);
    char ch[n][8][8];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<8;j++)
        {
            for(int u=0;u<8;u++)
            {
                ~scanf(" %c",&ch[i][j][u]);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=0;j<8;j++)
        {
            for(int u=0;u<8;u++)
            {
                if(ch[i][j][u]=='*')
                {
                    k=0;
                    if(j>0&&ch[i][j-1][u]=='L')chs(ch[i],-1,0,0,j,u);
                    if(j<7&&ch[i][j+1][u]=='L')chs(ch[i],1,0,0,j,u);
                    if(u>0&&ch[i][j][u-1]=='L')chs(ch[i],0,-1,0,j,u);
                    if(u<7&&ch[i][j][u+1]=='L')chs(ch[i],0,1,0,j,u);
                    if(j>0&&u>0&&ch[i][j-1][u-1]=='L')chs(ch[i],-1,-1,0,j,u);
                    if(j>0&&u<7&&ch[i][j-1][u+1]=='L')chs(ch[i],-1,1,0,j,u);
                    if(j<7&&u>0&&ch[i][j+1][u-1]=='L')chs(ch[i],1,-1,0,j,u);
                    if(j<7&&u<7&&ch[i][j+1][u+1]=='L')chs(ch[i],1,1,0,j,u);
                }
                if(sum<k){sum=k;}
            }
        }
        printf("Case %d: %d",i+1,sum);
        printf("\n");
    }
}
