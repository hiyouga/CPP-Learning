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
    setlocale(LC_ALL, "");//设置程序语言为中文（能显示中文字符
    LinkList head = (LinkList)malloc(sizeof(LinkNode));
    //建立链表头结点，以后链表都以head来寻找
    head -> nxt = NULL;//记得设置链表区域为空指针
    init(head);//初始化程序
    system("pause");
    return 0;
}

void init(LinkList t)
{
	int menu;//菜单操作变量
	printf("\n\t%ls\n\n",L"欢迎使用图书信息管理系统！");
    do{
        printf(" -------------\n");
    	printf(" |%-7ls|\n",L"1.录入数据");
    	printf(" |%-7ls|\n",L"2.浏览数据");
    	printf(" |%-9ls|\n",L"3.排序");
    	printf(" |%-7ls|\n",L"4.查询数据");
    	printf(" |%-7ls|\n",L"5.统计数据");
    	printf(" |%-7ls|\n",L"6.删除数据");
    	printf(" |%-7ls|\n",L"7.修改数据");
    	printf(" |%-7ls|\n",L"8.保存数据");
    	printf(" |%-7ls|\n",L"9.读入数据");
    	printf(" |%-7ls|\n",L"0.退出程序");
        printf(" -------------\n");
        printf("%ls",L"请输入选项(0-9)：");
	    scanf("%d", &menu);
	    fflush(stdin);//清空输入缓冲区
	    switch(menu)//switch选择结构
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
	    	default:printf("%ls\n",L"输入错误");
	    }
    }while(menu);//输入0的话可以退出，否则循环
}

void insert(LinkList t)//添加图书信息
{
	LinkNode r;//直接定义一个结构体变量
	r.nxt = NULL;
	printf("%ls",L"图书编号：");scanf("%d", &r.aid);fflush(stdin);
	printf("%ls",L"书名：");_getws(r.name);
	printf("%ls",L"作者：");_getws(r.auth);
	printf("%ls",L"出版社：");_getws(r.pub);
	printf("%ls",L"出版时间：");scanf("%d", &r.time);
	printf("%ls",L"价格：");scanf("%lf", &r.price);
	fflush(stdin);
	InsertList(t, &r);//使用插入节点函数添加到链表尾部
}

void view(LinkList t)//显示当前所有图书信息
{
    DispList(t);
}

void sort(LinkList t)//以图书编号为顺序排序
{
    SortList(t);
    printf("%ls\n",L"排序完成！");
}

void query(LinkList t)//查询图书
{
    int w;
    printf("%ls\n",L"1.按图书编号");
    printf("%ls\n",L"2.按作者");
    scanf("%d", &w);
    if(w == 1){
        int id;
        printf("%ls",L"图书编号：");
        scanf("%d", &id);
        FindListId(t, id);//根据图书编号查找图书
    }else if(w == 2){
        wchar_t au[MAXN];
        printf("%ls",L"作者：");
        scanf("%ls", au);
        FindListAuth(t, au);//根据作者查找图书
    }else{
        printf("%ls\n",L"输入错误");
    }
    fflush(stdin);
}

void stat(LinkList t)//按照出版社统计图书
{
    wchar_t pu[MAXN];
    printf("%ls",L"出版社：");
    scanf("%ls", pu);
    fflush(stdin);
    StatList(t, pu);
}

void del(LinkList t)//删除图书
{
    int id;
    printf("%ls",L"图书编号：");scanf("%d", &id);
    fflush(stdin);
    DeleteList(t, id);
    printf("%ls\n",L"删除成功！");
}

void modify(LinkList t)//修改图书
{
    int id;
    LinkNode r;//定义一个结构体变量
    printf("%ls",L"图书编号：");scanf("%d", &id);
    fflush(stdin);
	r.nxt = NULL;
	r.aid = id;
	printf("%ls",L"书名：");scanf("%ls", r.name);
	printf("%ls",L"作者：");scanf("%ls", r.auth);
	printf("%ls",L"出版社：");scanf("%ls", r.pub);
	printf("%ls",L"出版时间：");scanf("%d", &r.time);
	printf("%ls",L"价格：");scanf("%lf", &r.price);
	fflush(stdin);
    ModifyList(t, &r);
}

void save(LinkList t)//保存链表内容到二进制文件
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
    printf("%ls\n",L"保存成功！");
    fclose(fp);
}

void load(LinkList t)//读取二进制文件中链表内容
{
	FILE * fp;//文件指针
	LinkNode buf;//临时变量
    if ((fp = fopen("book.data", "rb")) == NULL) {
        fprintf(stderr, "Cannot open data file.\n");
        return;
    }
    DestroyList(t);///删除旧表
	while(fread(&buf, sizeof(LinkNode), 1, fp)){
        buf.nxt = NULL;///防止建表错误
    	InsertList(t, &buf);
	}
	printf("%ls\n",L"读取成功！");
    fclose(fp);
}
