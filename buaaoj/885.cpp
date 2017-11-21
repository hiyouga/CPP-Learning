/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 341287
 Created at: Wed Oct 25 2017 17:58:04 GMT+0800 (CST)
 Problem_id: 885	Time: 5	Memory: 2624
*/

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
int a,b,c;
cin>>a>>b>>c;
int d=max(max(abs(a),abs(b)),max(abs(b),abs(c)));
if(d==abs(a)){
    cout<<a;
}else if(d==abs(b)){
    cout<<b;
}else{
    cout<<c;
}
}
