/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 340286
 Created at: Wed Oct 25 2017 00:31:16 GMT+0800 (CST)
 Problem_id: 29	Time: 4	Memory: 2820
*/

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    double a,b,c,d;
    char op;
    while(cin>>a>>b>>c>>d>>op){
        cout<<fixed<<setprecision(2);
        switch(op)
        {
        case '+':
            cout<<a+c<<" "<<b+d;
            break;
        case '-':
            cout<<a-c<<" "<<b-d;
            break;
        case '*':
            cout<<a*c-b*d<<" "<<a*d+c*b;
            break;
        case '/':
            cout<<(a*c+b*d)/(c*c+d*d)<<" "<<(c*b-a*d)/(c*c+d*d);
break;
        }
        cout<<endl;
    }
}
