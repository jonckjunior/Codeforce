#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vector<vi> adj;
vi color, vis;

int solve(int u, int p){
    int res = (color[u] != p);
    vis[u] = 1;
    for(int v : adj[u])
        if(!vis[v])
            res += solve(v, color[u]);
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    int n; cin >> n;
    adj.assign(n+5, vi());
    color.assign(n+5, 0);
    vis.assign(n+5, 0);
    
    for(int i = 2; i <= n; i++){
        int x; cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    
    for(int i = 1; i <= n; i++)
        cin >> color[i];
        
    cout << solve(1, -1) << endl;
    
    return 0;
}
