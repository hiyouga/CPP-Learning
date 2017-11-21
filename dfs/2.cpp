#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct Node {
    int e,nxt;
}node[200005];
int n,num,maxdep,nd,sd;
int h[100005];
void add(int s,int e){
    node[++num].e=e;
    node[num].nxt=h[s];
    h[s]=num;
}
void dfs(int dep,int u,int pre){
    if(dep>maxdep){
        maxdep=dep;
        nd=u;
    }
    int i=h[u];
    while(i){
        if(node[i].e!=pre)
            dfs(dep+1,node[i].e,u);
        i=node[i].nxt;
    }
}
int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        int a[n],b[n],c[n];
        for(int p=0;p<n;p++){
            cin >> a[p];
            c[p]=a[p];
        }
        int r[n-1][2];
        for(int q=0;q<n-1;q++){
            cin >> r[q][0] >> r[q][1];
        }
        sort(a,a+n);
        b[0]=a[0];
        int v=0;
        for(int w=1;w<n;w++){
            if(a[w]!=b[v]){
                v++;
                b[v]=a[w];
            }
        }
        cout<<"Case "<<i+1<<":"<<endl;
        for(int z=0;z<=v;z++){
            memset(h,0,sizeof(h));
            num=0;
            maxdep=0,nd=0;
            for(int q=0;q<n-1;q++){
                if(c[r[q][0]-1]==b[z] && c[r[q][1]-1]==b[z]){
                    add(r[q][0],r[q][1]);
                    add(r[q][1],r[q][0]);
                }
            }
            for(int w=0;w<n;w++){
                if(c[w]==b[z]){
                    sd=w+1;
                    dfs(maxdep,sd,0);
                    maxdep=0;
                    dfs(maxdep,nd,0);
                }
            }
            cout<<"color "<<b[z]<<":"<<maxdep+1<<endl;
        }
        cout<<endl;
    }
}
