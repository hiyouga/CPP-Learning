#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

int main()
{
    int n, code, flag;
    string temp, name[8] = {"QBH","PPY","NZXM","PPG","WJJ","ZZZ","RYAN","HCC"};
    int cot[8], num[8][105], res[3], all[3];
    cin >> n;
    memset(res, 0, sizeof(res));
    memset(all, 0, sizeof(all));
    memset(cot, 0, sizeof(cot));
    for(int i = 0; i < n; i++){
        cin >> temp >> code;
        if(code < 0) code = -code;
        if(code % 2)
            code = 1;
        else
            code = 2;
        for(int j = 0; j < 8; j++){
            if(name[j] == temp){
                num[j][cot[j]++] = code;
            }
        }
    }
    for(int p = 0; p < cot[5]; p++)
        for(int q = 0; q < cot[0]; q++)
            for(int r = 0; r < cot[7]; r++){
                if(((num[0][q]+num[5][p]) % 2 == 1) && ((num[5][p] + num[7][r]) % 2 == 1)) res[0]++;
                all[0]++;
            }
    for(int p = 0; p < cot[4]; p++)
        for(int q = 0; q < cot[2]; q++)
            for(int r = 0; r < cot[1]; r++){
                if((num[4][p]+num[2][q]+num[1][r]) % 2 == 1) res[1]++;
                all[1]++;
            }
    for(int p = 0; p < cot[6]; p++)
        for(int q = 0; q < cot[3]; q++){
            if((num[6][p]+num[3][q]) % 2 == 1) res[2]++;
            all[2]++;
        }
    cout << all[0] * all[1] * all[2] - res[0] * res[1] * res[2]<< endl;
    return 0;
}
