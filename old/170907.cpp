#include<bits/stdc++.h>
int * sort_a(int *);
int * sort_b(int *);
int main()
{
    using namespace std;
    int a[10];
    for(int i=0;i<10;i++){
        cin >> a[i];
    }
    int * b = a;
    b = sort_b(b);
    for(int r=0;r<10;r++){
        cout << a[r] << ends;
    }
    int f,m;
    cin >> f;
    bool flag=0;
    int l=0,r=9;
    while(!flag&&l<=r){
        m=(l+r)/2;
        if(f==a[m]){
            flag=1;
        }
        if(f<a[m]){
            r=m-1;
        }
        if(f>a[m]){
            l=m+1;
        }
    }
    if(flag){
        cout << "Found in " << m << endl;
    }else{
        cout << "Not existed!" << endl;
    }
}
int * sort_a(int * w){
    for(int p=0;p<10;p++){
        for(int q=0;q<9-p;q++){
            if(w[q]>w[q+1]){
                int temp = w[q+1];
                w[q+1]=w[q];
                w[q]=temp;
            }
        }
    }
    return w;
}
int * sort_b(int * w){
    for(int p=0;p<10;p++){
        int min_at = p;
        for(int q=p;q<10;q++){
            min_at=w[min_at]>w[q]?q:min_at;
        }
        if(min_at!=p){
            int temp = w[p];
            w[p]=w[min_at];
            w[min_at]=temp;
        }
    }
    //return w;
}
//7 9 12 18 25 45 33 39 60 21
