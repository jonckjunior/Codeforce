#include <bits/stdc++.h>

using namespace std;

int main() {
	string s; cin >> s;
	bool flag = true;
	for(int i = 1; i < s.size(); i++){
		if(s[i] >= 'a' && s[i] <= 'z')
			flag = false;
	}
	if(flag == false) cout << s << endl;
	else{
		for(int i = 0; i < s.size(); i++){
			if(s[i] >= 'a' && s[i] <= 'z')
				s[i] = toupper(s[i]);
			else
				s[i] = tolower(s[i]);
		}
		cout << s << endl;
	}
	return 0;
}