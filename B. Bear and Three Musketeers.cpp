#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vector<vi> adj;

int main(){
    int n, m; cin >> n >> m;
    adj.assign(n+5, vi());
    
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int u = 1; u <= n; u++)
        sort(adj[u].begin(), adj[u].end());
    
    int ans = 1e9;
    for(int u = 1; u <= n; u++){
        for(int v : adj[u]){
            vi res;
            set_intersection(adj[u].begin(), adj[u].end(), adj[v].begin(), adj[v].end(), back_inserter(res));
            for(int w : res)
                if(w != u && w != v)
                    ans = min(ans, (int)adj[u].size()+(int)adj[v].size()+(int)adj[w].size() - 2*3);
        }
    }
    if(ans >= 1e9) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
