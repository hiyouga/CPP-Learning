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
    struct node * nxt;
} LinkNode, * LinkList;

void swapint(int * m, int * n)
{
    int t;
    t = *m;
    *m = *n;
    *n = t;
}

void swapdlb(double * m, double * n)
{
    double t;
    t = *m;
    *m = *n;
    *n = t;
}

void swapwcs(wchar_t * m, wchar_t * n)
{
    wchar_t t[MAXN];
    int l = sizeof(wchar_t) * MAXN;
    memcpy(t, m, l);
    memcpy(m, n, l);
    memcpy(n, t, l);
}

void swapnode(LinkList s, LinkList p)
{
    swapint(&((*s).aid), &((*p).aid));
    swapwcs(s->name, p->name);
    swapwcs(s->auth, p->auth);
    swapwcs(s->pub, p->pub);
    swapint(&((*s).time), &((*p).time));
    swapdlb(&((*s).price), &((*p).price));
}

void prt_node(LinkList p)
{
    printf("%ls%d\n", L"\x56fe\x4e66\x7f16\x53f7\xff1a", p -> aid);
    printf("%ls%ls\n", L"\x4e66\x540d\xff1a", p -> name);
    printf("%ls%ls\n", L"\x4f5c\x8005\xff1a", p -> auth);
    printf("%ls%ls\n", L"\x51fa\x7248\x793e\xff1a", p -> pub);
    printf("%ls%d\n", L"\x51fa\x7248\x65f6\x95f4\xff1a", p -> time);
    printf("%ls%.2f\n", L"\x4ef7\x683c\xff1a", p -> price);
    printf("\n");
}

void InsertList(LinkList t, LinkList e)
{
	LinkList p, q;
	q = t;
	while(q -> nxt != NULL){
		q = q -> nxt;
	}
	p = (LinkList)malloc(sizeof(LinkNode));
	memcpy(p, e, sizeof(LinkNode));
	q -> nxt = p;
}

void DispList(LinkList t)
{
    LinkList q;
    q = t->nxt;
    while(q != NULL){
        prt_node(q);
        q = q -> nxt;
    }
}

void SortList(LinkList t)
{
    LinkList p, q, s;
    int mid;
    double z;
    if(t->nxt == NULL) return;
    for(p = t->nxt; p->nxt != NULL; p = p->nxt){
        s = p;
        for(q = p->nxt; q != NULL; q = q->nxt){
            if(q->aid > s->aid) s = q;
        }
        if(s != p){
            swapnode(s, p);
        }
    }
}

void DeleteList(LinkList t, int id)
{
    LinkList pre, p;
    pre = t;
    p = pre->nxt;
    while(p != NULL){
        if(p->aid == id){
            pre->nxt = p->nxt;
            free(p);
            break;
        }
        pre = p;
        p = p->nxt;
    }
}

void DestroyList(LinkList t)
{
    LinkList pre, p;
    pre = t->nxt;
    if(pre == NULL) return;
    t->nxt = NULL;
    p = pre->nxt;
    while(p != NULL){
        free(pre);
        pre = p;
        p = p->nxt;
    }
    free(pre);
}

void FindListId(LinkList t, int id)
{
    LinkList p;
    p = t->nxt;
    while(p != NULL){
        if(p->aid == id)
            prt_node(p);
        p = p->nxt;
    }
}

void FindListAuth(LinkList t, const wchar_t * au)
{
    LinkList p;
    p = t->nxt;
    while(p != NULL){
        if(!wcscmp(p->auth, au))
            prt_node(p);
        p = p->nxt;
    }
}

void ModifyList(LinkList t, LinkList e)
{
    LinkList p;
    p = t->nxt;
    while(p != NULL){
        if(p->aid == e->aid){
            swapnode(p, e);
            break;
        }
        p = p->nxt;
    }
}

void StatList(LinkList t, const wchar_t * pu)
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
    printf("%ls%d%ls\n", L"\x5171\x7edf\x8ba1\x5230", cnt, L"\x672c\x4e66\x3002");

}

#endif // LINKLIST_H_INCLUDED
