#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

int main()
{
    int n, code;
    unsigned long long sum;
    string temp, name[8] = {"QBH","PPY","NZXM","PPG","WJJ","ZZZ","RYAN","HCC"};
    int cot[8], num[8][105], res[3], all[3], lop[8];
    cin >> n;
    memset(res, 0, sizeof(res));
    memset(all, 0, sizeof(all));
    memset(cot, 0, sizeof(cot));
    for(int i = 0; i < n; i++){
        cin >> temp >> code;
        for(int j = 0; j < 8; j++){
            if(name[j] == temp){
                num[j][cot[j]++] = code;
            }
        }
    }
    for(lop[0]=0;lop[0]<cot[0];lop[0]++){
        for(lop[1]=0;lop[1]<cot[1];lop[1]++){
            for(lop[2]=0;lop[2]<cot[2];lop[2]++){
                for(lop[3]=0;lop[3]<cot[3];lop[3]++){
                    for(lop[4]=0;lop[4]<cot[4];lop[4]++){
                        for(lop[5]=0;lop[5]<cot[5];lop[5]++){
                            for(lop[6]=0;lop[6]<cot[6];lop[6]++){
                                for(lop[7]=0;lop[7]<cot[7];lop[7]++){
                                    sum = (num[0][lop[0]]+num[5][lop[5]])*(num[4][lop[4]]+num[2][lop[2]]+num[1][lop[1]])*(num[5][lop[5]]+num[7][lop[7]])*(num[6][lop[6]]+num[3][lop[3]]);
                                    if(sum % 2 == 0) res[0]++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << res[0] << endl;
}
