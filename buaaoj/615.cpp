#include <iostream>
#include <cstring>
#define is_end(c) ((c == '.') || (c == '?') || (c == '!'))

using namespace std;

int main()
{
	string str, temp;
	while(getline(cin, temp)){
		str += temp + "\n";
	}
	//cout << str << endl;
	bool state_b = true;
	for(int i = 0; i < str.length(); i++){
		if(state_b && str[i] >= 97 && str[i] <= 122){
			str[i] -= 32;
			state_b = false;
		}else if(is_end(str[i])){
			state_b = true;
		}else if(str[i]=='"' || str[i]=='\'' || (str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'Z')){
			state_b = false;
		}
	}
	for(int i = 0; i < str.length() - 1; i++){
		cout << str[i];
	}
}