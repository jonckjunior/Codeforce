#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;

vector<vi> adj;
ll vis[150005], node, edge;

void solve(int u){
    vis[u] = 1;
    node++;
    for(int v : adj[u]){
        edge++;
        if(!vis[v])
            solve(v);
    }
}

int main(){
    ios::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    adj.assign(n+5, vi());
    
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool found = true;
    for(int i = 1; i <= n; i++)
        if(!vis[i] && !adj[i].empty()){
            node = edge = 0;
            solve(i);
            //printf("edge = %d\n", edge);
            //printf("node = %d\n", node);
            if(edge != node*(node-1))
                found = false;
        }
    if(found) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
