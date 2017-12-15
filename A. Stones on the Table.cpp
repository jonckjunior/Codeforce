#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin >> n;
	string s; cin >> s;
	int len = s.size(), pos = 0, res = 0;
	while(pos < len){
		int aux = 0;
		while(pos+1 < len && s[pos] == s[pos+1])
			aux++,pos++;
		pos++;
		if(aux) res+=aux;
	}
	cout << res << endl;
	return 0;
}