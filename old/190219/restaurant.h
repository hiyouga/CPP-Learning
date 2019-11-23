#include "stdafx.h"

// 房间数量
const int LARGE_NUM = 2;
const int MEDIUM_NUM = 10;
const int SMALL_NUM = 20;

class Restaurant
{
private:
    vector<Customer> customers; // Customer customers[100]; 顾客变量
    vector<Orderform> orders; // 订单变量
public:
    Restaurant(); // 构造函数
    ~Restaurant(); // 析构函数
    void addCustomer(); // 添加顾客
    void dumpCustomer(); // 打印顾客
    void modifyCustomer(); // 修改顾客信息
    void deleteCustomer(); // 删除顾客
    Customer * searchCustomer(wchar_t * name); // 依照姓名搜索顾客
    void requestOrder(); // 新增订单
    void dumpOrder(); // 打印订单
    void queryOrder(); // 查询订单
    void deleteOrder(); // 删除订单
};

bool cmp(Orderform &a, Orderform &b) // 自定义“小于”函数
{
    return a.getDate() < b.getDate();
}

Restaurant::Restaurant()
{
    Customer customer;
    ifstream inFile_a("customers.dat", ios::in | ios::binary); // 定义文件输入流
    if (inFile_a) {
        while (inFile_a.read((char*)&customer, sizeof(Customer))) { // 读取文件必须转换为(char*)
            customers.push_back(customer); // 向vector后部添加一个值
        }
        inFile_a.close(); // 关闭文件
    }
    Orderform order;
    ifstream inFile_b("orders.dat", ios::in | ios::binary);
    if (inFile_b) {
        while (inFile_b.read((char*)&order, sizeof(Orderform))) {
            orders.push_back(order);
        }
        inFile_b.close();
    }
}

Restaurant::~Restaurant()
{
    ofstream outFile_a("customers.dat", ios::out | ios::binary); // 定义文件输出流
    for (int i = 0; i < customers.size(); i++) {
        outFile_a.write((char*)&(customers[i]), sizeof(Customer));
    }
    outFile_a.close();
    ofstream outFile_b("orders.dat", ios::out | ios::binary);
    for (int i = 0; i < orders.size(); i++) {
        outFile_b.write((char*)&(orders[i]), sizeof(Orderform));
    }
    outFile_b.close();
}

void Restaurant::addCustomer()
{
    Customer editing;
    editing.input();
    if (searchCustomer(editing.getName())) {
        printf("%ls\n", L"姓名重复，添加失败！");
    } else {
        customers.push_back(editing);
        printf("%ls\n", L"添加成功！");
    }
}

void Restaurant::dumpCustomer()
{
    for (int i = 0; i < customers.size(); i++) {
        customers[i].dump();
    }
}

void Restaurant::modifyCustomer()
{
    printf("%ls", L"请输入姓名：");
    fflush(stdin);
    wchar_t name[MAXLEN];
    _getws(name);
    Customer * person;
    if (person = searchCustomer(name)) {
        person->input();
        printf("%ls", L"修改成功！");
    } else {
        printf("%ls\n", L"查无此人！");
    }
}

void Restaurant::deleteCustomer()
{
    printf("%ls", L"请输入姓名：");
    fflush(stdin);
    wchar_t name[MAXLEN];
    _getws(name);
    for (int i = 0; i < customers.size(); i++) {
        if (!wcscmp(customers[i].getName(), name)) {
            customers.erase(customers.begin()+i);
            printf("%ls\n", L"删除成功");
            return;
        }
    }
    printf("%ls\n", L"查无此人！");
}

Customer * Restaurant::searchCustomer(wchar_t * name)
{
    for (int i = 0; i < customers.size(); i++) {
        if (!wcscmp(customers[i].getName(), name)) { // ==strcmp比较字符串相等
            return &(customers[i]);
        }
    }
    return NULL;
}

void Restaurant::requestOrder()
{
    printf("%ls", L"请输入预订日期（yyyymmdd）：");
    int date;
    scanf("%d", &date);
    int countSmall = 0; // 当日已有的订单数
    int countMedium = 0;
    int countLarge = 0;
    bool flagLarge[2] = {0}; // 分配房间号用
    bool flagMedium[10] = {0};
    bool flagSmall[20] = {0};
    for (int i = 0; i < orders.size(); i++) {
        if (orders[i].getDate() == date) {
            switch (orders[i].getSize()) {
                case LARGE:
                    flagLarge[orders[i].getNo()-1] = true; // 房间号已被占用
                    countLarge++; // 当日订单数增加
                    break;
                case MEDIUM:
                    flagMedium[orders[i].getNo()-1] = true;
                    countMedium++;
                    break;
                case SMALL:
                    flagSmall[orders[i].getNo()-1] = true;
                    countSmall++;
                    break;
                default: break;
            }
        }
    }
    if (countLarge == LARGE_NUM && countMedium == MEDIUM_NUM && countSmall == SMALL_NUM) {
        printf("%ls\n", L"当日无可预定房间");
        return;
    }
    printf("%ls%d%ls%d%ls%d%ls\n", L"目前还剩余", LARGE_NUM - countLarge, L"个20人间，", MEDIUM_NUM - countMedium, L"个10人间和", SMALL_NUM - countSmall, L"个6人间");
    printf("%ls", L"请输入想要预订的房间大小（20/10/6）：");
    int rawsize;
    scanf("%d", &rawsize);
    int size;
    int no;
    switch (rawsize) {
        case 20:
            if (countLarge < LARGE_NUM) {
                for (int i = 0; i < 2; i++) {
                    if (!flagLarge[i]) {
                        no = i+1; // 分配房间号
                        break;
                    }
                }
                size = LARGE; // 规定房间大小
                break;
            } else { return; }
        case 10:
            if (countMedium < MEDIUM_NUM) {
                for (int i = 0; i < 10; i++) {
                    if (!flagMedium[i]) {
                        no = i+1;
                        break;
                    }
                }
                size = MEDIUM;
                break;
            } else { return; }
        case 6: 
            if (countSmall < SMALL_NUM) {
                for (int i = 0; i < 20; i++) {
                    if (!flagSmall[i]) {
                        no = i+1;
                        break;
                    }
                }
                size = SMALL;
                break;
            } else { return; }
        default: return;
    }
    fflush(stdin);
    printf("%ls", L"请输入姓名：");
    wchar_t name[MAXLEN];
    _getws(name);
    if (searchCustomer(name)) {
        orders.push_back(Orderform(date, size, no, name));
        printf("%ls\n", L"预订成功！");
    } else {
        printf("%ls\n", L"查无此人！");
    }
}

void Restaurant::dumpOrder()
{
    sort(orders.begin(), orders.end(), cmp); // 按照预订日期排序
    for (int i = 0; i < orders.size(); i++) {
        orders[i].dump();
    }
}

void Restaurant::queryOrder()
{
    int w;
    printf("%ls\n", L"1.按顾客姓名");
    printf("%ls\n", L"2.按日期规格");
    scanf("%d", &w);
    if (w == 1) {
        fflush(stdin);
        printf("%ls", L"请输入姓名：");
        wchar_t name[MAXLEN];
        _getws(name);
        for (int i = 0; i < orders.size(); i++) {
            if (!wcscmp(orders[i].getOwner(), name)) {
                orders[i].dump();
            }
        }
    } else {
        printf("%ls", L"请输入预订日期（yyyymmdd）：");
        int date;
        scanf("%d", &date);
        printf("%ls", L"请输入规格（20/10/6）：");
        int rawsize;
        scanf("%d", &rawsize);
        int size;
        switch (rawsize) {
            case 20: size = LARGE; break;
            case 10: size = MEDIUM; break;
            case 6: size = SMALL; break;
            default: break;
        }
        for (int i = 0; i < orders.size(); i++) {
            if (orders[i].getDate() == date && orders[i].getSize() == size) {
                orders[i].dump();
            }
        }
    }
}

void Restaurant::deleteOrder()
{
    printf("%ls", L"请输入预订日期（yyyymmdd）：");
    int date;
    scanf("%d", &date);
    printf("%ls", L"请输入规格（20/10/6）：");
    int rawsize;
    scanf("%d", &rawsize);
    int size;
    switch (rawsize) {
        case 20: size = LARGE; break;
        case 10: size = MEDIUM; break;
        case 6: size = SMALL; break;
        default: break;
    }
    printf("%ls", L"请输入桌号：");
    int no;
    scanf("%d", &no);
    for (int i = 0; i < orders.size(); i++) {
        if (orders[i].getDate() == date && orders[i].getSize() == size && orders[i].getNo() == no) {
            orders.erase(orders.begin()+i); // 删除变量
            printf("%ls\n", L"删除成功");
            return;
        }
    }
    printf("%ls\n", L"删除失败！");
}