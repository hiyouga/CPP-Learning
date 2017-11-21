/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 315721
 Created at: Thu Oct 12 2017 11:14:59 GMT+0800 (CST)
 Problem_id: 8	Time: 1	Memory: 2672
*/

#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        long long a,b,c,d,e,f,g,h;
        cin>>a>>b>>c>>d>>e>>f>>g>>h;
        cout<<a*c/b+d*g*h/e/f<<endl;
    }
}
