#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int color[100005];
vector<vi> adj;
set<int> countColor[100005];

int main(){
    int n, m; cin >> n >> m;
    adj.assign(n+5, vi());
    for(int i = 1; i <= n; i++)
        cin >> color[i];
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int res, maxres = 0;
    
    for(int u = 1; u <= n; u++){
        int c = color[u];
        countColor[c].insert(c);
        for(int v : adj[u])
            countColor[c].insert(color[v]);
    }
    
    for(int c = 1; c <= 100000; c++){
        if(countColor[c].size() > maxres){
            res = c;
            maxres = countColor[c].size();
        }
    }
    
    cout << res << endl;
    return 0;
}
