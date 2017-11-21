#include <cstdio>
#include <cstring>

using namespace std;

struct Node {
    int e,nxt;
}node[200005];//数组模拟链表

int n,num,maxDep,nd;
int h[100005];

void add(int s,int e) {//加边
    node[++num].e=e;
    node[num].nxt=h[s];
    h[s]=num;
}

void dfs(int dep,int u,int pre) {
    if(dep>maxDep) {//如果该路径的长度大于maxDep，更新maxDep和最长路的端点
        maxDep=dep;
        nd=u;
    }
    int i=h[u];
    while(i) {
        if(node[i].e!=pre)//因为是树，所以只用判断当前节点的前一个节点是否与其下一个节点相同
            dfs(dep+1,node[i].e,u);
        i=node[i].nxt;
    }
}

int main() {
    int s,e,i;
    while(1==scanf("%d",&n)) {
        memset(h,0,sizeof(h));
        num=0;
        for(i=1;i<n;++i) {
            scanf("%d%d",&s,&e);
            add(s,e);
            add(e,s);
        }
        maxDep=0,nd=0;
        dfs(0,1,0);//找到最长路的一个端点
        maxDep=0;
        dfs(0,nd,0);//找到最长路的长度
        printf("%d\n",maxDep);
    }
    return 0;
}
