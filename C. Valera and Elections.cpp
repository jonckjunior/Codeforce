#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> adj;
vii level_node;
int vis[100005], pai[100005];

void solve(int u, int dep){
    vis[u] = 1;
    for(ii v : adj[u])
        if(!vis[v.first]){
            pai[v.first] = u;
            if(v.second == 2)
                level_node.push_back(ii(dep+1, v.first));
            solve(v.first, dep+1);
        }
}

void dfs(int u){
    if(u == 1) return;
    vis[u] = 1;
    if(!vis[pai[u]])
        dfs(pai[u]);
}

int main(){
    int n; cin >> n;
    adj.assign(n+5, vii());
    
    for(int i = 0; i < n-1; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back(ii(v,w));
        adj[v].push_back(ii(u,w));
    }
    pai[1] = -1;
    solve(1, 0);
    sort(level_node.rbegin(), level_node.rend());
    vi res;
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < (int)level_node.size(); i++){
        int u = level_node[i].second;
        if(!vis[u]){
            res.push_back(u);
            dfs(u);
        }
    }
    cout << res.size() << endl;
    for(int u : res)
        cout << u << " ";
    cout << endl;
    return 0;
}
