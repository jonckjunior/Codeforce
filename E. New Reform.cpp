#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vector<vi> adj;
vi vis;

bool solve(int u, int p){
    vis[u] = 1;
    bool res = false;
    for(int v : adj[u]){
        if(v != p){
            if(!vis[v])
                res |= solve(v, u);
            else
                res = true;
        }
    }
    return res;
}

int main(){
    
    int n, m; cin >> n >> m;
    adj.assign(n+5, vi());
    vis.assign(n+5, 0);
    
    
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int res = 0;
    for(int i = 1; i <= n; i++)
        if(!vis[i] && !solve(i, -1))
            res++;
    cout << res << endl;
    return 0;
}
