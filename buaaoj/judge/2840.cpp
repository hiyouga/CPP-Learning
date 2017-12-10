#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

int main()
{
    int x, y, n, cx, cy, sco = 0;
    char com, mar[10][10];

    cin >> x >> y >> n;

    for(int p = 0; p < 10; p++){
        for(int q = 0; q < 10; q++){
            mar[p][q] = ' ';
        }
    }

    mar[x][y] = 'M';

    cout << "score:" << sco << endl;
    cout << "============" << endl;
    for(int p = 0; p < 10; p++){
        cout << '|';
        for(int q = 0; q < 10; q++){
            cout << mar[p][q];
        }
        cout << '|' << endl;
    }
    cout << "============" << endl << endl;

    for(int i = 0; i < n; i++){
        cin >> com;
        if(com == 'f'){
            cin >> cx >> cy;
            mar[cx][cy] = '*';
            continue;
        }
        if(com == 'w' && x > 0){
            if(mar[x][y] != '*') mar[x][y] = ' ';
            x--;
            if(mar[x][y] == '*') sco++;
            mar[x][y] = 'M';
        }
        if(com == 's' && x < 9){
            if(mar[x][y] != '*') mar[x][y] = ' ';
            x++;
            if(mar[x][y] == '*') sco++;
            mar[x][y] = 'M';
        }
        if(com == 'a' && y > 0){
            if(mar[x][y] != '*') mar[x][y] = ' ';
            y--;
            if(mar[x][y] == '*') sco++;
            mar[x][y] = 'M';
        }
        if(com == 'd' && y < 9){
            if(mar[x][y] != '*') mar[x][y] = ' ';
            y++;
            if(mar[x][y] == '*') sco++;
            mar[x][y] = 'M';
        }
        if(com == 'q'){
            if(mar[x][y] == '*') sco++;
            mar[x][y] = 'M';
        }
        cout << "score:" << sco << endl;
        cout << "============" << endl;
        for(int p = 0; p < 10; p++){
            cout << '|';
            for(int q = 0; q < 10; q++){
                cout << mar[p][q];
            }
            cout << '|' << endl;
        }
        cout << "============" << endl << endl;
    }

}
