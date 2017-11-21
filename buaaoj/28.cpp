/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 323606
 Created at: Thu Oct 19 2017 20:19:19 GMT+0800 (CST)
 Problem_id: 28	Time: 2	Memory: 2688
*/

#include<iostream>
using namespace std;
int main()
{
    int t,a,b,s;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a>>b;
        int flag=0;
        for(int p=a;p<=b;p++){
            s=(p/100)*(p/100)*(p/100)+(p/10%10)*(p/10%10)*(p/10%10)+(p%10)*(p%10)*(p%10);
            if(s==p){
            cout<<p<<" ";
            flag++;
            }
        }
        if(!flag){
            cout<<-1;
        }
        cout<<endl;
    }
}
