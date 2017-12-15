#include <bits/stdc++.h>

using namespace std;
int main() {
    string s; cin >> s;
    int aux = 0;
    for(int i = 0; i < (int)s.size(); i++){
    	if(s[i] == '4' || s[i] == '7')
    		aux++;
    }
    s = to_string(aux);
    bool flag = true;
    for(int i = 0; i < (int)s.size(); i++){
    	if(s[i] != '4' && s[i] != '7')
    		flag = false;
    }
    if(flag) puts("YES");
    else puts("NO");
    return 0;
}