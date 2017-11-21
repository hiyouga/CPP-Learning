/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 341531
 Created at: Wed Oct 25 2017 19:12:44 GMT+0800 (CST)
 Problem_id: 889	Time: 6	Memory: 1492
*/

#include<cstdio>
using namespace std;
int main()
{
    int t;char p;
    scanf("<%d><%c>",&t,&p);
    if(p=='F'){
        printf("<%d><%c>=<%.1f><%c>",t,p,(t-32)*5.0/9.0,'C');
    }else{
        printf("<%d><%c>=<%.1f><%c>",t,p,t*9.0/5.0+32,'F');
    }
}
