#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int dp[105][10005], sum;

int solve(int u, int w){
	if(u == v.size()) return w;
	if(dp[u][w] != -1) return dp[u][w];
	int res = min(solve(u+1, abs(w + v[u])), solve(u+1, abs(w - v[u])));
	return dp[u][w] = res;
}

int main(){
	int n;
	while(cin >> n, n != 0){
		memset(dp, -1, sizeof dp);
		v.clear();
		for(int i = 0; i < n; i++){
			int x; cin >> x;
			v.push_back(x);
		}
		cout << solve(0,0) << endl;
	}
	return 0;
}
