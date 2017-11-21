/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 336566
 Created at: Mon Oct 23 2017 22:31:00 GMT+0800 (CST)
 Problem_id: 878	Time: 3	Memory: 2684
*/

#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<a/b+(a%b>0?1:0);
}
