#include "stdafx.h"
#include "linklist.h"

void init(LinkList);
void insert(LinkList);
void view(LinkList);
void sort(LinkList);
void query(LinkList);
void stat(LinkList);
void del(LinkList);
void modify(LinkList);
void save(LinkList);
void load(LinkList);

int main()
{
    setlocale(LC_ALL, "");
    LinkList head = (LinkList)malloc(sizeof(LinkNode));
    head -> nxt = NULL;
    init(head);
    system("pause");
    return 0;
}

void init(LinkList t)
{
    int menu;
    printf("\n\t%ls\n\n",L"\x6b22\x8fce\x4f7f\x7528\x56fe\x4e66\x4fe1\x606f\x7ba1\x7406\x7cfb\x7edf\xff01");
    do{
        printf(" -------------\n");
        printf(" |%-7ls|\n",L"\x31\x2e\x5f55\x5165\x6570\x636e");
        printf(" |%-7ls|\n",L"\x32\x2e\x6d4f\x89c8\x6570\x636e");
        printf(" |%-9ls|\n",L"\x33\x2e\x6392\x5e8f");
        printf(" |%-7ls|\n",L"\x34\x2e\x67e5\x8be2\x6570\x636e");
        printf(" |%-7ls|\n",L"\x35\x2e\x7edf\x8ba1\x6570\x636e");
        printf(" |%-7ls|\n",L"\x36\x2e\x5220\x9664\x6570\x636e");
        printf(" |%-7ls|\n",L"\x37\x2e\x4fee\x6539\x6570\x636e");
        printf(" |%-7ls|\n",L"\x38\x2e\x4fdd\x5b58\x6570\x636e");
        printf(" |%-7ls|\n",L"\x39\x2e\x8bfb\x5165\x6570\x636e");
        printf(" |%-7ls|\n",L"\x30\x2e\x9000\x51fa\x7a0b\x5e8f");
        printf(" -------------\n");
        printf("%ls",L"\x8bf7\x8f93\x5165\x9009\x9879\x28\x30\x2d\x39\x29\xff1a");
        scanf("%d", &menu);
        fflush(stdin);
        switch(menu)
        {
            case 1:insert(t);break;
            case 2:view(t);break;
            case 3:sort(t);break;
            case 4:query(t);break;
            case 5:stat(t);break;
            case 6:del(t);break;
            case 7:modify(t);break;
            case 8:save(t);break;
            case 9:load(t);break;
            case 0:break;
            default:printf("%ls\n",L"\x8f93\x5165\x9519\x8bef");
        }
    }while(menu);
}

void insert(LinkList t)
{
    LinkNode r;
    r.nxt = NULL;
    printf("%ls",L"\x56fe\x4e66\x7f16\x53f7\xff1a");scanf("%d", &r.aid);fflush(stdin);
    printf("%ls",L"\x4e66\x540d\xff1a");_getws(r.name);
    printf("%ls",L"\x4f5c\x8005\xff1a");_getws(r.auth);
    printf("%ls",L"\x51fa\x7248\x793e\xff1a");_getws(r.pub);
    printf("%ls",L"\x51fa\x7248\x65f6\x95f4\xff1a");scanf("%d", &r.time);
    printf("%ls",L"\x4ef7\x683c\xff1a");scanf("%lf", &r.price);
    fflush(stdin);
    InsertList(t, &r);
}

void view(LinkList t)
{
    DispList(t);
}

void sort(LinkList t)
{
    SortList(t);
    printf("%ls\n",L"\x6392\x5e8f\x5b8c\x6210\xff01");
}

void query(LinkList t)
{
    int w;
    printf("%ls\n",L"\x31\x2e\x6309\x56fe\x4e66\x7f16\x53f7");
    printf("%ls\n",L"\x32\x2e\x6309\x4f5c\x8005");
    scanf("%d", &w);
    if(w == 1){
        int id;
        printf("%ls",L"\x56fe\x4e66\x7f16\x53f7\xff1a");
        scanf("%d", &id);
        FindListId(t, id);
    }else if(w == 2){
        wchar_t au[MAXN];
        printf("%ls",L"\x4f5c\x8005\xff1a");
        scanf("%ls", au);
        FindListAuth(t, au);
    }else{
        printf("%ls\n",L"\x8f93\x5165\x9519\x8bef");
    }
    fflush(stdin);
}

void stat(LinkList t)
{
    wchar_t pu[MAXN];
    printf("%ls",L"\x51fa\x7248\x793e\xff1a");
    scanf("%ls", pu);
    fflush(stdin);
    StatList(t, pu);
}

void del(LinkList t)
{
    int id;
    printf("%ls",L"\x56fe\x4e66\x7f16\x53f7\xff1a");scanf("%d", &id);
    fflush(stdin);
    DeleteList(t, id);
    printf("%ls\n",L"\x5220\x9664\x6210\x529f\xff01");
}

void modify(LinkList t)
{
    int id;
    LinkNode r;
    printf("%ls",L"\x56fe\x4e66\x7f16\x53f7\xff1a");scanf("%d", &id);
    fflush(stdin);
    r.nxt = NULL;
    r.aid = id;
    printf("%ls",L"\x4e66\x540d\xff1a");_getws(r.name);
    printf("%ls",L"\x4f5c\x8005\xff1a");_getws(r.auth);
    printf("%ls",L"\x51fa\x7248\x793e\xff1a");_getws(r.pub);
    printf("%ls",L"\x51fa\x7248\x65f6\x95f4\xff1a");scanf("%d", &r.time);
    printf("%ls",L"\x4ef7\x683c\xff1a");scanf("%lf", &r.price);
    fflush(stdin);
    ModifyList(t, &r);
}

void save(LinkList t)
{
    FILE * fp;
    if ((fp = fopen("book.data", "wb")) == NULL) {
        fprintf(stderr, "Cannot open data file.\n");
        return;
    }
    while(t -> nxt != NULL){
        fwrite(t -> nxt, sizeof(LinkNode), 1, fp);
        t = t -> nxt;
    }
    printf("%ls\n",L"\x4fdd\x5b58\x6210\x529f\xff01");
    fclose(fp);
}

void load(LinkList t)
{
    FILE * fp;
    LinkNode buf;
    if ((fp = fopen("book.data", "rb")) == NULL) {
        fprintf(stderr, "Cannot open data file.\n");
        return;
    }
    DestroyList(t);///É¾³ý¾É±í
    while(fread(&buf, sizeof(LinkNode), 1, fp)){
        buf.nxt = NULL;///·ÀÖ¹½¨±í´íÎó
        InsertList(t, &buf);
    }
    printf("%ls\n",L"\x8bfb\x53d6\x6210\x529f\xff01");
    fclose(fp);
}
