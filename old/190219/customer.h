#include "stdafx.h"

class Customer
{
private:
    wchar_t name[MAXLEN];
    int gender;
    char tel[MAXLEN];
public:
    wchar_t * getName() { return name; }
    void input(); // 输入基本信息
    void dump(); // 打印到屏幕
    Customer() {}
    ~Customer() {}
};

void Customer::input()
{
    printf("%ls", L"请输入姓名：");
    fflush(stdin); // 清空输入缓存区
    _getws(name); // 宽字符的输入函数
    printf("%ls", L"请输入性别(0为男性，1为女性)：");
    scanf("%d", &gender);
    printf("%ls", L"请输入联系电话：");
    fflush(stdin);
    scanf("%s", tel);
}

void Customer::dump()
{
    printf("%ls%ls\n", L"姓名：", name);
    if (gender) {
        printf("%ls\n", L"性别：女");
    } else {
        printf("%ls\n", L"性别：男");
    }
    printf("%ls%s\n", L"联系电话：", tel);
}