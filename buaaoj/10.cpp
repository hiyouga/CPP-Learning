/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 315990
 Created at: Thu Oct 12 2017 19:21:54 GMT+0800 (CST)
 Problem_id: 10	Time: 1	Memory: 2624
*/

#include<iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n){
        unsigned long long pre=1,now=1,temp;
        for(int i=0;i<n;i++){
            temp=(pre+now)%100007;
            pre=now;
            now=temp;
        }
        cout<<now<<endl;
    }
}
