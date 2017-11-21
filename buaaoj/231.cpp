/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 360797
 Created at: Sun Oct 29 2017 17:18:08 GMT+0800 (CST)
 Problem_id: 231	Time: 4	Memory: 2636
*/

#include<iostream>
#include<cstring>
using namespace std;
int h[105][105],f[105][105];
void flow(int x,int y,int a,int b)
{
    f[x][y]=1;
    //cout<<x<<y<<f[x][y]<<h[x][y]<<endl;
    //up
    if((x>0)&&(f[x-1][y]!=1)&&(h[x][y]>=h[x-1][y])){
        flow(x-1,y,a,b);
    }
    //down
    if((x<a-1)&&(f[x+1][y]!=1)&&(h[x][y]>=h[x+1][y])){
        flow(x+1,y,a,b);
    }
    //left
    if((y>0)&&(f[x][y-1]!=1)&&(h[x][y]>=h[x][y-1])){
        flow(x,y-1,a,b);
    }
    //right
    if((y<b-1)&&(f[x][y+1]!=1)&&(h[x][y]>=h[x][y+1])){
        flow(x,y+1,a,b);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    while(cin>>n>>m){
        memset(h,0,sizeof(h));
        memset(f,0,sizeof(f));
        for(int p=0;p<n;p++){
            for(int q=0;q<m;q++){
                cin>>h[p][q];
            }
        }
        int k;
        cin>>k;
        int w[k][2];
        for(int i=0;i<k;i++){
            cin>>w[i][0]>>w[i][1];
            flow(w[i][0]-1,w[i][1]-1,n,m);
        }
        for(int r=0;r<n;r++){
            for(int s=0;s<m;s++){
                cout<<f[r][s];
            }
            cout<<endl;
        }
    }
}
