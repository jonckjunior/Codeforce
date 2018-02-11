#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vector<vi> adj;

int gov[1005], vis[1005], node, edge;

void solve(int u){
    vis[u] = 1;
    node++;
    edge += adj[u].size();
    for(int v : adj[u])
        if(!vis[v])
            solve(v);
}

int main(){
    int n, m, k; cin >> n >> m >> k;
    adj.assign(n+5, vi());
    for(int i = 0; i < k; i++){
        cin >> gov[i];
    }
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    long long int res = 0;
    int maxi = 0;
    for(int i = 0; i < k; i++){
        int u = gov[i];
        if(!vis[u]){
            node = edge = 0;
            solve(u);
            //printf("comp %d com %d nodos e %d arestas\n", u, node, edge);
            maxi = max(maxi, node);
            res += (node*(node-1) - edge)/2;
        }
    }
    for(int i = 1; i <= n; i++)
        if(!vis[i]){
            node = edge = 0;
            solve(i);
            res += (node*(node-1) - edge)/2;
            res += node*maxi;
            maxi += node;
        }
    cout << res << endl;
    
    return 0;
}
