#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vector<vi> adj;

int dp[50005][505], n, k;

int solve(int u, int p){
    dp[u][0] = 1;
    int res = 0;
    for(int v : adj[u]){
        if(v != p){
            res += solve(v, u);
            for(int j = 1; j <= k; j++)
                res += dp[v][j-1]*dp[u][k-j];
            for(int j = 1; j <= k; j++)
                dp[u][j] += dp[v][j-1];
        }
    }
    return res;
}

int main(){
    cin >> n >> k;
    adj.assign(n+5, vi());
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << solve(1, -1) << endl;
    return 0;
}
