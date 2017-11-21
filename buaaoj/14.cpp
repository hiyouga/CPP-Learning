/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 385861
 Created at: Tue Nov 07 2017 21:11:28 GMT+0800 (CST)
 Problem_id: 14	Time: 80	Memory: 7108
*/

#include<iostream>
using namespace std;
int a[1000005],b[1000005];
long long Merge(int lt,int mid,int rt)
{
    long long sum=0;
    int s=lt,t=mid+1,k=lt;
    while(s<=mid&&t<=rt){
        if(a[s]<=a[t]){
            b[k++]=a[s++];
        }else{
            sum+=mid-lt+1-(s-lt);
            b[k++]=a[t++];
        }
    }
    while(s<=mid){
        b[k++]=a[s++];
    }
    while(t<=rt){
        b[k++]=a[t++];
    }
    for(int i=lt;i<=rt;i++){
        a[i]=b[i];
    }
    return sum;
}
long long MergeSort(int lt,int rt)
{
    if(lt<rt){
        int mid=(lt+rt)/2;
        long long k1=MergeSort(lt,mid);
        long long k2=MergeSort(mid+1,rt);
        long long k3=Merge(lt,mid,rt);
        return k1+k2+k3;
    }else{
        return 0;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin>>n){
        for(int k=1;k<=n;k++){
            cin>>a[k];
        }
        cout<<MergeSort(1,n)<<endl;
    }
    return 0;
}
