#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int maxn = 30005;

int gem[maxn], dp[maxn][505], n, d;

int solve(int u, int k){
	if(u >= maxn || k == 0)
		return 0;
	int aux = k - (d-250);
	if(dp[u][aux] != -1)
		return dp[u][aux];
	int res = 0;
	for(int i = -1; i <= 1; i++)
		res = max(res, solve(u+k+i, k+i));
	return dp[u][aux] = res + gem[u];
}

int main(){
    ios::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    cin >> n >> d;
    for(int i = 0; i < n; i++){
    	int x; cin >> x;
    	gem[x]++;
    }

    cout << solve(d, d) << endl;

    return 0;
}
