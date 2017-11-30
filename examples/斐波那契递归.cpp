#include <iostream>

using namespace std;
//!ps:时间复杂度较高
long fib(int x)
{
    switch(x){
        case 0:return 0;
        case 1:case 2:return 1;
    }
    return (fib(x-1)+fib(x-2));
}
int main()
{
    int n = 15;
    cout << fib(n);
}
