#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vector<vi> adj;
vi vis;

int solve(int u){
    vis[u] = 1;
    int res = 1;
    for(int v : adj[u])
        if(!vis[v])
            res += solve(v);
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    adj.assign(n+5, vi());
    vis.assign(n+5, 0);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int maxi = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i])
            maxi += solve(i) - 1;
    }
    cout << (1LL << maxi) << endl;
    return 0;
}
