/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 315713
 Created at: Thu Oct 12 2017 11:04:40 GMT+0800 (CST)
 Problem_id: 6	Time: 3	Memory: 2616
*/

#include<iostream>
using namespace std;
int main()
{
    int num;
    while(cin >> num){
        num = num/100+num/10%10*10+num%10*100;
        cout<<num<<endl;
    }
}
