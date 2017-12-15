#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin >> n;
	for(int i = n+1; ; i++){
		string s = to_string(i);
		map<int, int> mapa;
		bool flag = true;
		for(int j = 0; j < (int)s.size(); j++){
			mapa[s[j]]++;
			if(mapa[s[j]] > 1) flag = false;
		}
		if(flag) {
			cout << s << endl;
			break;
		}
	}
    return 0;
}