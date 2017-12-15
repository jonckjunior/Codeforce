#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    int len = s.size();
    string pattern = "hello";
    int pos = 0;
    for(int i = 0; i < len && pos < 5; i++){
    	if(s[i] == pattern[pos])
    		pos++;
    }
    if(pos == 5) puts("YES");
    else puts("NO");
    return 0;
}