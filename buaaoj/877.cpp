/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 336565
 Created at: Mon Oct 23 2017 22:29:57 GMT+0800 (CST)
 Problem_id: 877	Time: 3	Memory: 2616
*/

#include<iostream>
using namespace std;
int NUM(char x){
    return x-'0';
}
int main()
{
    char a[8];
    cin>>a;
    int i=(NUM(a[0])*9+NUM(a[1])*8+NUM(a[2])*7+NUM(a[3])*6+NUM(a[4])*5+NUM(a[5])*4+NUM(a[6])*3+NUM(a[7])*2)%10;
    for(int p=0;p<8;p++){
        cout<<a[p];
    }
    cout<<i;
}
