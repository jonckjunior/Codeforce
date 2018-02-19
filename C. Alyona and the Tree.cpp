#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int cost[100005], dp[100005];
vector<vii> adj;

int dfs(int u, int p){
    int res = 1;
    for(ii par : adj[u])
        if(par.first != p)
            res += dfs(par.first, u);
    return dp[u] = res;
}

int solve(int u, int p, int sum){
    if(sum > cost[u])
        return dp[u];
    sum = max(sum, 0);
    int res = 0;
    for(ii par : adj[u]){
        if(par.first != p)
            res += solve(par.first, u, sum + par.second);
    }
    return res;
}

int main(){
    int n; cin >> n;
    adj.assign(n+5, vii());
    
    for(int i = 1; i <= n; i++)
        cin >> cost[i];
    for(int i = 1; i <= n-1; i++){
        int u, w; cin >> u >> w;
        adj[i+1].push_back(ii(u,w));
        adj[u].push_back(ii(i+1,w));
    }
    
    dfs(1, -1);
    
    cout << solve(1, -1, 0) << endl;
    
    return 0;
}
