#include <bits/stdc++.h>

using namespace std;

int main() {
	string s; cin >> s;
	int len = s.size();
	int pos = 0;
	bool flag = false;
	while(pos < len){
		int aux = 1;
		while(pos+1 < len && s[pos] == s[pos+1])
			aux++,pos++;
		pos++;
		if(aux >= 7) flag = true;
	}
	if(flag) puts("YES");
	else puts("NO");
	return 0;
}