#include "stdafx.h"
#include "customer.h"
#include "orderform.h"
#include "restaurant.h"

void init(Restaurant top) // 程序初始化
{
    int menu; // 菜单选择项
    printf("\n\t%ls\n\n", L"欢迎使用酒店餐桌预订管理系统！");
    do {
        printf(" ----------------\n");
        printf(" |%-10ls|\n", L"1.添加顾客");
        printf(" |%-8ls|\n", L"2.浏览全部顾客");
        printf(" |%-8ls|\n", L"3.修改顾客信息");
        printf(" |%-10ls|\n", L"4.删除顾客");
        printf(" |%-10ls|\n", L"5.新增预订");
        printf(" |%-8ls|\n", L"6.浏览全部预订");
        printf(" |%-8ls|\n", L"7.查询预订信息");
        printf(" |%-10ls|\n", L"8.取消预订");
        printf(" |%-10ls|\n", L"0.退出程序");
        printf(" ----------------\n");
        printf("%ls", L"请输入选项(0-8)：");
        scanf("%d", &menu);
        switch (menu) // 菜单选择结构
        {
            case 1: top.addCustomer(); break;
            case 2: top.dumpCustomer(); break;
            case 3: top.modifyCustomer(); break;
            case 4: top.deleteCustomer(); break;
            case 5: top.requestOrder(); break;
            case 6: top.dumpOrder(); break;
            case 7: top.queryOrder(); break;
            case 8: top.deleteOrder(); break;
            case 0: printf("\n%ls\n\n", L"感谢您的使用，再见！"); break;
            default: printf("%ls\n", L"输入错误");
        }
    } while (menu);
}

int main()
{
    setlocale(LC_ALL, ""); // 设置程序语言为中文
    init(Restaurant());
    system("pause"); // 暂停程序再退出
    return 0;
}