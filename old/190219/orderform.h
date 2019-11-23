#include "stdafx.h"

class Orderform
{
private:
	int date; // 预订日期
    int size; // 房间大小
    int no; // 桌号
    wchar_t owner[MAXLEN]; // 预订人姓名
public:
    Orderform() {}
    Orderform(int _date, int _size, int _no, wchar_t * _owner);
    int getDate() { return date; }
    int getSize() { return size; }
    int getNo() { return no; }
    wchar_t * getOwner() { return owner; }
    void dump(); // 打印信息到屏幕
};

Orderform::Orderform(int _date, int _size, int _no, wchar_t * _owner)
{
    date = _date;
    size = _size;
    no = _no;
    wcscpy(owner, _owner); // ==strcpy复制字符串
}

void Orderform::dump()
{
	printf("%ls%d\n", L"日期：", date);
	switch (size) {
		case LARGE: printf("%ls\n", L"规格：20人桌"); break;
		case MEDIUM: printf("%ls\n", L"规格：10人桌"); break;
		case SMALL: printf("%ls\n", L"规格：6人桌"); break;
	}
	printf("%ls%d\n", L"桌号：", no);
	printf("%ls%ls\n", L"预约人：", owner);
}