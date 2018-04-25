// linklist.h : definition for the linklist ADT

#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

typedef struct node{
    int aid;
    wchar_t name[MAXN];
    wchar_t auth[MAXN];
    wchar_t pub[MAXN];
    int time;
    double price;
    struct node * nxt;//下一个指向的节点
} LinkNode, * LinkList;

void swapint(int * m, int * n)//整数的交换
{
    int t;
    t = *m;
    *m = *n;
    *n = t;
}

void swapdlb(double * m, double * n)//浮点数的交换
{
    double t;
    t = *m;
    *m = *n;
    *n = t;
}

void swapwcs(wchar_t * m, wchar_t * n)//字符串的交换
{
    wchar_t t[MAXN];
    int l = sizeof(wchar_t) * MAXN;
    memcpy(t, m, l);
    memcpy(m, n, l);
    memcpy(n, t, l);
}

void swapnode(LinkList s, LinkList p)//交换链表节点
{
    swapint(&((*s).aid), &((*p).aid));
    swapwcs(s->name, p->name);
    swapwcs(s->auth, p->auth);
    swapwcs(s->pub, p->pub);
    swapint(&((*s).time), &((*p).time));
    swapdlb(&((*s).price), &((*p).price));
}

void prt_node(LinkList p)//打印节点
{
    printf("%ls%d\n", L"图书编号：", p -> aid);
    printf("%ls%ls\n", L"书名：", p -> name);
    printf("%ls%ls\n", L"作者：", p -> auth);
    printf("%ls%ls\n", L"出版社：", p -> pub);
    printf("%ls%d\n", L"出版时间：", p -> time);
    printf("%ls%.2f\n", L"价格：", p -> price);
    printf("\n");
}

void InsertList(LinkList t, LinkList e)//将链表尾部插入一个节点
{
	LinkList p, q;
	q = t;
	while(q -> nxt != NULL){//将q指针一直指到链表最后一个节点
		q = q -> nxt;
	}
	p = (LinkList)malloc(sizeof(LinkNode));
	memcpy(p, e, sizeof(LinkNode));//将新添加的内容拷贝到新节点中
	q -> nxt = p;//添加节点到链表尾部
}

void DispList(LinkList t)//遍历打印链表节点
{
    LinkList q;
    q = t->nxt;
    while(q != NULL){
        prt_node(q);//打印节点
        q = q -> nxt;
    }
}

void SortList(LinkList t)//将链表内容排序
{
    LinkList p, q, s;
    if(t->nxt == NULL) return;//如果链表为空直接退出
    for(p = t->nxt; p->nxt != NULL; p = p->nxt){//实现简单的选择排序
        s = p;
        for(q = p->nxt; q != NULL; q = q->nxt){
            if(s->aid < q->aid) s = q;
        }
        if(s != p){
            swapnode(s, p);//交换两节点
        }
    }
}

void DeleteList(LinkList t, int id)//删除链表节点
{
    LinkList pre, p;
    pre = t;
    p = pre->nxt;
    while(p != NULL){//遍历链表
        if(p->aid == id){//符合条件
            pre->nxt = p->nxt;//将前一个节点指向本节点的下一个节点
            free(p);//删除本节点
            break;
        }
        pre = p;
        p = p->nxt;
    }
}

void DestroyList(LinkList t)//销毁整个链表
{
    LinkList pre, p;
    pre = t->nxt;
    if(pre == NULL) return;
    t->nxt = NULL;//头部节点nxt值设置为NULL
    p = pre->nxt;
    while(p != NULL){
        free(pre);//删除前一个节点
        pre = p;
        p = p->nxt;//移动到下一个节点
    }
    free(pre);//删除最后一个节点
}

void FindListId(LinkList t, int id)//根据图书编号查找
{
    LinkList p;
    p = t->nxt;
    while(p != NULL){
        if(p->aid == id)//符合条件
            prt_node(p);
        p = p->nxt;
    }
}

void FindListAuth(LinkList t, const wchar_t * au)//根据作者查找
{
    LinkList p;
    p = t->nxt;
    while(p != NULL){
        if(!wcscmp(p->auth, au))//符合条件
            prt_node(p);
        p = p->nxt;
    }
}

void ModifyList(LinkList t, LinkList e)//修改节点内容
{
    LinkList p;
    p = t->nxt;
    while(p != NULL){
        if(p->aid == e->aid){//符合条件
            swapnode(p, e);//交换节点内容
            break;
        }
        p = p->nxt;
    }
}

void StatList(LinkList t, const wchar_t * pu)//按照出版社统计图书
{
    int cnt = 0;
    LinkList p;
    p = t -> nxt;
    while(p != NULL){
        if(!wcscmp(p -> pub, pu)){
            prt_node(p);
            cnt++;
        }
        p = p -> nxt;
    }
    printf("%ls%d%ls\n", L"共统计到", cnt, L"本书。");

}

#endif // LINKLIST_H_INCLUDED
