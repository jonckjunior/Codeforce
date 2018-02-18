#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vector<vi> adj;
vi vis;

int solve(int u, int p){
    vis[u] = 2;
    int res = 0;
    for(int v : adj[u]){
        if(v != p){
            if(!vis[v])
                res += solve(v, u);
            else if(vis[v] == 2)
                res++;
        }
    }
    vis[u] = 1;
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
    
    int res = 0, comp = 0;
    for(int i = 1; i <= n; i++)
        if(!vis[i]){
            res += solve(i, -1);
            comp++;
        }
    //cout << res << endl;
    if(res == 1 && comp == 1) cout << "FHTAGN!" << endl;
    else cout << "NO" << endl;
    return 0;
}
