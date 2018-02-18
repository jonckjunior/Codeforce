#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vector<vi> adj;
vi vis;

int solve(int u){
    int numViz = adj[u].size();
    for(int v : adj[u])
        if(vis[v])
            numViz--;
    return numViz;
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
    vi removidos;
    int res = 0;
    do{
        removidos.clear();
        for(int i = 1; i <= n; i++){
            //printf("vizinhos de %d = %d\n", i, solve(i));
            if(!vis[i] && solve(i) == 1)
                removidos.push_back(i);
        }
        for(int x : removidos){
            vis[x] = 1;
            //printf("removendo %d\n", x);
        }
        if(!removidos.empty()) res++;
    }while(!removidos.empty());
    cout << res << endl;
    return 0;
}
