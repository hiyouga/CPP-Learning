#include<iostream>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OK 1
#define ERROR 0
using namespace std;
typedef char Selemtype;
struct Sqstack{
    Selemtype base[STACK_INIT_SIZE];
    Selemtype * top;
};
Sqstack Mystack;
int init_s(Sqstack &S){
    if(S.base == NULL){
        return ERROR;
    }else{
        S.top = S.base;
        return OK;
    }
}
int push(Sqstack &S, Selemtype e){
    if((S.top-S.base) >= STACK_INIT_SIZE){
        return ERROR;
    }else{
        *S.top = e;
        S.top++;
        return OK;
    }
}
int main()
{

}
