#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int pos[10][1005], dp[1005];
vvi adj, perm;

int solve(int u){
	if(dp[u] != -1)
		return dp[u];
	int res = 0;
	for(int v : adj[u])
		res = max(res, solve(v));
	return dp[u] = res + 1;
}

int main(){
    ios::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);

    int n, k; cin >> n >> k;
    adj.assign(n+5, vi());

    for(int i = 1; i <= k; i++){
    	vi vec;
    	for(int j = 1; j <= n; j++){
    		int x; cin >> x;
    		vec.push_back(x);
    		pos[i][x] = j;
    	}
    	perm.push_back(vec);
    }

    for(int i = 1; i <= n; i++)
    	for(int j = 1; j <= n; j++){
    		if(i == j) continue;
    		bool flag = true;
    		for(int l = 1; l <= k; l++)
    			if(pos[l][i] > pos[l][j])
    				flag = false;
    		if(flag)
    			adj[i].push_back(j);
    	}

    int res = 0;
    for(int i = 1; i <= n; i++)
    	res = max(res, solve(i));
    cout << res << endl;
    return 0;
}
