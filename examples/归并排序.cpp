//CPP MergeSort
#include<iostream>
#define MAXSIZE 10000

using namespace std;

int a[MAXSIZE], temp[MAXSIZE];

void Merge(int * f, int lt, int mid, int rt)
{
    int p = lt;//mid in
    int q = mid + 1;//mid+1 in
    int k = lt;//new arr
    while(p <= mid && q <= rt){
        if(f[p] < f[q]){
            temp[k++] = f[p++];
        }else{
            temp[k++] = f[q++];
        }
    }
    while(p <= mid)
        temp[k++] = f[p++];
    while(q <= rt)
        temp[k++] = f[q++];
    for(int i = lt; i <= rt ;i++){
        f[i] = temp[i];
    }
}

void MergeSort(int * f, int lt, int rt)
{
    if(lt < rt){
        int mid = (lt + rt) / 2;
        MergeSort(f, lt, mid);
        MergeSort(f, mid+1, rt);
        Merge(f, lt, mid, rt);
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    MergeSort(a, 0, n-1);

    for(int i = 0; i < n; i++){
        cout << a[i];
        if(i != n-1) cout << " ";
    }

    return 0;
}
