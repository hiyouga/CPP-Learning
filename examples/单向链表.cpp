#include <iostream>

using namespace std;
typedef int Elemtype;

struct Node{//�ڵ�ṹ
    Elemtype val;
    Node * nxt;
};

typedef Node * Ld;

Ld InitList(Ld LinkList, int n)//!�����ʼ��
{
    Ld temp, r = LinkList;
    Elemtype tempi;
    for(int i = 0;i < n; i++){
        cin >> tempi;
        temp = new Node;
        temp->val = tempi;
        temp->nxt = NULL;
        if(LinkList == NULL){
            LinkList = temp;
        }else{
            r->nxt = temp;
        }
        r = temp;
    }
    return LinkList;
}

void InsertHead(Ld &LinkList, Elemtype item)//!ͷ������
{
    Ld temp;
    temp = new Node;
    temp->val = item;
    temp->nxt = LinkList;
    LinkList = temp;
}

void InsertTail(Ld LinkList, Elemtype item)//!β������
{
    Ld temp, r;
    temp = new Node;
    r = LinkList;
    while(r->nxt != NULL){//�ƶ���ĩβ
        r = r->nxt;
    }
    temp->val = item;
    temp->nxt = NULL;
    r->nxt = temp;
}

int LinkLength(Ld LinkList)//!���㳤��
{
    if(LinkList != NULL){
        return LinkLength(LinkList->nxt) + 1;
    }else{
        return 0;
    }
}

int LinkEmpty(Ld LinkList)//!�Ƿ�Ϊ��
{
    return LinkList == NULL;
}

Ld LinkFind(Ld LinkList, Elemtype item)//!����Ԫ��
{
    if(LinkList == NULL || LinkList->val == item){
        return LinkList;
    }else{
        return LinkFind(LinkList->nxt, item);
    }
}

void InsertPtr(Ld LinkList, Ld ptr, Elemtype item)//!ָ������
{
    Ld temp;
    temp = new Node;
    temp->val = item;
    if(LinkEmpty(LinkList)){
        LinkList = temp;
        temp->nxt = NULL;
    }else{
        temp->nxt = ptr->nxt;
        ptr->nxt = temp;
    }
}

Elemtype DeleteLink(Ld &LinkList, Ld ptr, Ld pre)//!ɾ��ָ��ڵ�
{
    if(LinkList == ptr){
        LinkList = ptr->nxt;
    }else{
        pre->nxt = ptr->nxt;
    }
    Elemtype tempi = ptr->val;
    delete ptr;
    return tempi;
}

void DestroyLink(Ld &LinkList)//!��������
{
    Ld temp = LinkList;
    while(temp != NULL){
        LinkList = temp->nxt;
        delete temp;
        temp = LinkList;
    }
}

void PrintLink(Ld LinkList)//!������ӡ����
{
    Ld temp = LinkList;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->nxt;
    }
    cout << endl;
}

void InvertLink(Ld &LinkList)//!��ת����
{
    Ld pre, nwd, temp;
    pre = LinkList;
    nwd = NULL;
    while(pre != NULL){
        temp = nwd;
        nwd = pre;
        pre = pre->nxt;
        nwd->nxt = temp;
    }
    LinkList = nwd;
}

int main()
{
    int n;
    cin >> n;
    Ld List = NULL;//��������׵�ַ

    //�������� 5 1 3 5 2 4
    List = InitList(List, n);
    InsertHead(List, 23);
    InsertTail(List, 32);
    cout << LinkLength(List) << endl;
    Ld f = LinkFind(List, 5);
    InsertPtr(List, f, 78);
    PrintLink(List);
    InvertLink(List);
    PrintLink(List);

    return 0;
}
