#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;


int cost[100005], vis[100005];
vector<vi> adj;

int solve(int u){
    vis[u] = 1;
    int res = cost[u];
    for(int v : adj[u])
        if(!vis[v])
            res = min(res, solve(v));
    return res;
}

int main(){
    int n, m; cin >> n >> m;
    adj.assign(n+5, vi());
    for(int i = 1; i <= n; i++)
        cin >> cost[i];
        
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    ll res = 0;
    for(int i = 1; i <= n; i++)
        if(!vis[i])
            res += solve(i);
    cout << res << endl;
    return 0;
}
