#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define RADIX 10
#define CARRY_RADIX 65536
#define BIT_PRE_WORD 32

using namespace std;

struct Bigint
{
    int len;
    string num;
};

bool Rsb(Bigint &dst, Bigint &src)
{

}

bool judge(int n)
{
    int k = 0;
    while((n >> k) != 0) k++;
    if(n == 0)
        return false;
    for(int i = k; i > 0; i--)
        if(judge(n-k) == false)
            return true;
    return false;
}

int main()
{
    //NOTLE
    int t;
    scanf("%d\n", &t);
    //string n;
    Bigint m;
    int n;
    for(int i = 1; i <= t; i++){
        cin >> m.num;
        m.len = m.num.length();

        /*cin >> n;
        if(judge(n)){
            printf("Case #%d: Win!\n", i);
        }else{
            printf("Case #%d: Lose.\n", i);
        }*/
    }
}
