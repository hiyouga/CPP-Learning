/*
 Author: Ö£Ò«Íþ
 Result: TLE	Submission_id: 343213
 Created at: Thu Oct 26 2017 11:38:19 GMT+0800 (CST)
 Problem_id: 31	Time: 1000	Memory: 0
*/

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    unsigned long n,x;
    while(cin>>n>>x){
        int s=0;
        for(int i=n;i>=sqrt(x);i--){
            if(x%i==0){
                s++;
            }
        }
        cout<<s*2<<endl;
    }
}
