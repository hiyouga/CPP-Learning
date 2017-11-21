#include <cstdio>
#include <cstring>

using namespace std;

struct Node {
    int e,nxt;
}node[200005];//����ģ������

int n,num,maxDep,nd;
int h[100005];

void add(int s,int e) {//�ӱ�
    node[++num].e=e;
    node[num].nxt=h[s];
    h[s]=num;
}

void dfs(int dep,int u,int pre) {
    if(dep>maxDep) {//�����·���ĳ��ȴ���maxDep������maxDep���·�Ķ˵�
        maxDep=dep;
        nd=u;
    }
    int i=h[u];
    while(i) {
        if(node[i].e!=pre)//��Ϊ����������ֻ���жϵ�ǰ�ڵ��ǰһ���ڵ��Ƿ�������һ���ڵ���ͬ
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
        dfs(0,1,0);//�ҵ��·��һ���˵�
        maxDep=0;
        dfs(0,nd,0);//�ҵ��·�ĳ���
        printf("%d\n",maxDep);
    }
    return 0;
}
