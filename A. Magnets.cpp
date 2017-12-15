#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin >> n;
	char last = '!';
	int res = 1;
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		if(s[0] == last) res++;
		last = s[1];
	}
	cout << res << endl;
    return 0;
}