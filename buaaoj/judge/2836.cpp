#include <iostream>
#include <cctype>
#include <cstring>
#include <sstream>
#define NOTLE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    int n, a, m;
    cin >> n;
    int mon[n];
    memset(mon, 0, sizeof(mon));
    string send, rec, name[n];
    for(int i = 0; i < n; i++)
        cin >> name[i];
    for(int i = 0; i < n; i++){
        cin >> send;
        cin >> a >> m;
        for(int j = 0; j < m; j++){
            cin >> rec;
            for(int r = 0; r < n; r++){
                if(name[r] == rec){
                    mon[r] += a / m;
                }
            }
        }
        for(int r = 0; r < n; r++){
            if(name[r] == send){
                if(m != 0)
                    mon[r] += a % m;
                else
                    mon[r] += a;
            }
        }
    }
    for(int i = 0; i < n; i++)
        cout << name[i] << " " << mon[i] << endl;
}
