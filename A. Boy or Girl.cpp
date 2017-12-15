#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    map<char,int> m;
    int res = 0;
    for(int i = 0; i < s.size(); i++){
    	m[s[i]]++;
    	if(m[s[i]] == 1) res++;
    }
    if(res&1) puts("IGNORE HIM!");
    else puts("CHAT WITH HER!");
    return 0;
}