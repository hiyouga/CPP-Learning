#include<iostream>
#include<cstring>
#include<cstdlib>
#include<sstream>
using namespace std;
char a[10000000];
main()
{
    int n,u;
    cin>>a;
    n=strlen(a);
    long sum=0;
    if(a[0]=='-')
        u=1;
    else
        u=0;
    for(int i=u;i<n;i++)
    {
        sum+=a[i]-'0';
    }
    while(sum>=10)
    {
        stringstream stream;
        string sun;
        stream<<sum;
        stream>>sun;
        n=sun.length();
        sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=atoi((sun.substr(i,1)).c_str());//ASCII to Integer
        }
    }
    cout<<sum<<endl;
}
