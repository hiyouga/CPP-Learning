/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 341297
 Created at: Wed Oct 25 2017 18:01:54 GMT+0800 (CST)
 Problem_id: 886	Time: 13	Memory: 2620
*/

#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    string month[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    int x;
    cin>>x;
    if(x>0&&x<13){
        cout<<month[x-1];
    }else{
        cout<<"Wrong month";
    }

}
