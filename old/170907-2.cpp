#include<bits/stdc++.h>
void sort_arr(int *,int);
int main()
{
    using namespace std;
    int a[5],b[7];
    for(int c=0;c<5;c++){
        cin >> a[c];
    }
    for(int d=0;d<7;d++){
        cin >> b[d];
    }
    int * pa = a;
    int * pb = b;
    sort_arr(pa,5);
    sort_arr(pb,7);
    for(int p=0;p<5;p++){
        cout << a[p] << ends;
    }
    cout << endl;
    for(int q=0;q<7;q++){
        cout << b[q] << ends;
    }
    cout << endl;
    int c[12];
    for(int k=0;k<12;k++){
        int p=0,q=0;
        if(a[p]>b[q]){
            c[k]=b[q];
            q++;
        }else{
            c[k]=a[p];
            p++;
        }
        if(p>=5){
            while(q<7){
                k++;
                c[k]=b[q];
                q++;
            }
            break;
        }
        if(q>=7){
            while(p<5){
                k++;
                c[k]=a[p];
                p++;
            }
            break;
        }
    }
    for(int u=0;u<12;u++){
        cout << c[u] << ends;
    }
}
void sort_arr(int * m,int s){
    for(int p=0;p<s;p++){
        int min_at = p;
        for(int q=p;q<s;q++){
            min_at = m[min_at]>m[q]?q:min_at;
        }
        if(min_at!=p){
            int temp = m[p];
            m[p] = m[min_at];
            m[min_at] = temp;
        }
    }
}
