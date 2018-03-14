#include <bits/stdc++.h>
using namespace std;

int dp[100005][30];
string s;

bool solve(int pos, char letra){
	if(dp[pos][letra] != -1)
		return dp[pos][letra];
	if(letra > 'z')
		return true;
	if(pos >= (int)s.size())
		return false;
	bool res = solve(pos+1, letra);
	if(res == false){
		if(s[pos] <= letra)
			res = solve(pos+1, letra+1);
		if(res == true)
			s[pos] = letra;
	}
	return dp[pos][letra] = res;
}

int main(){
	memset(dp, -1, sizeof dp);
    cin >> s;
    if(solve(0,'a')) cout << s << endl;
    else cout << -1 << endl;
    return 0;
}
