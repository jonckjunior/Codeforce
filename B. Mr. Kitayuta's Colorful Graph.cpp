#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

map<ii, vi> cores;
vector<vi> adj;
vi vis;

bool solve(int u, int dest, int c){
    vis[u] = 1;
    if(u == dest) return true;
    for(int v : adj[u]){
        bool ok = false;
        for(int cor : cores[ii(u,v)])
            if(cor == c) ok = true;
        if(ok && !vis[v] && solve(v,dest,c))
            return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    adj.assign(n+5, vi());

    for(int i = 0; i < m; i++){
        int u, v, c; cin >> u >> v >> c;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cores[ii(u,v)].push_back(c);
        cores[ii(v,u)].push_back(c);
    }
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int u, v; cin >> u >> v;
        int res = 0;
        for(int i = 1; i <= m; i++){
            vis.assign(n+5, 0);
            if(solve(u, v, i))
                res++;
        }
        cout << res << endl;
    }
    
    return 0;
}
