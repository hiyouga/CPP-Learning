/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 340126
 Created at: Tue Oct 24 2017 23:54:20 GMT+0800 (CST)
 Problem_id: 881	Time: 21	Memory: 2688
*/

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int a[500000];
int main()
{
    long long  n;
    cin>>n;
    for(int i=0;i<=255;i++)
    {
        long long m;
        m=(i<<1)&255;
        int t=(i)^(m);
        a[t]=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(i!=1) cout<<" ";
        int x;
        cin>>x;
        cout<<a[x];
    }
    return 0;
}
