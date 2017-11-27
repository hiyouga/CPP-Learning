#include <iostream>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int Partition(int * f, int lt, int rt)
{
    int t = f[rt], i = lt - 1;
    for(int j = lt; j < rt; j++){
        if(f[j] >= t){
            i++;
            swap(f[i], f[j]);
        }
    }
    swap(f[i+1], f[rt]);
    return i + 1;
}

void QuickSort(int * f, int lt, int rt)
{
    if(lt < rt){
        int mid = Partition(f, lt, rt);
        QuickSort(f, lt, mid-1);
        QuickSort(f, mid+1, rt);
    }
}


int main()
{
    NOTLE
    int n;
    cin >> n;
    int a[n];

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    QuickSort(a, 0, n-1);

    for(int i = 0; i < n; i++){
        cout << a[i];
        if(i != n-1) cout << " ";
    }
}
