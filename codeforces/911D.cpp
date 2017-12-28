#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int a[1505], b[1505];
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
    if(lt < rt){
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
    NOTLE
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int m;
    cin >> m;
    int p = MergeSort(0, n-1) % 2;
    while(m--){
        int l, r;
        cin >> l >> r;
        int q = (r-l+1)*(r-l)/2;
        p = (p + q) % 2;
        cout << (p%2==0?"even":"odd") << endl;
    }
    return 0;
}
