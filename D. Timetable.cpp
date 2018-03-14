#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int n, m, k;
int dp[505][505], dp2[505][505];
int tam[505];
vector<vi> adj;

int solve(int u, int f){
	if(f < 0) return 1e9;
	if(u >= n) return 0;
	if(dp2[u][f] != -1)	return dp2[u][f];
	int res = 1e9;
	for(int i = 0; i <= f; i++)
		if(i <= tam[u])
			res = min(res, solve(u+1, f-i) + dp[u][ tam[u] - i ]);
	return dp2[u][f] = res;
}

int main(){
	memset(dp2, -1, sizeof dp2);
	cin >> n >> m >> k;
	adj.assign(n+5, vi());

	for(int i = 0; i < n; i++){
		string s; cin >> s;
		for(int j = 0; j <(int)s.size(); j++)
			if(s[j] == '1')
				adj[i].push_back(j+1);
		tam[i] = (int)adj[i].size();
	}


	for(int i = 0; i < n; i++)
		for(int j = 1; j <= m; j++)
			dp[i][j] = 1e9;

	for(int i = 0; i < n; i++)
		for(int j = 1; j <= m; j++)
			for(int k = 0; k+j-1 < (int)adj[i].size(); k++)
				dp[i][j] = min(dp[i][j], adj[i][k+j-1] - adj[i][k] + 1);

/*	for(int i = 0; i < n; i++)
		for(int j = 0; j <= m; j++)
			printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);*/

	cout << solve(0, k) << endl;
    return 0;
}
