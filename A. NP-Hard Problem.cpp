#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vector<vi> adj;
vi color, p1, p2;

bool solve(int ss){
    queue<int> q; q.push(ss);
    color[ss] = 0;
    bool ok = true;
    while(!q.empty() && ok){
        int u = q.front(); q.pop();
        if(color[u] == 0) p1.push_back(u);
        else p2.push_back(u);
        for(int v : adj[u]){
            if(color[v] == color[u]) ok = false;
            else if(color[v] == -1){
                color[v] = !color[u];
                q.push(v);
            }
        }
    }
    return ok;
}

int main(){
    ios::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    adj.assign(n+5, vi());
    color.assign(100005, -1);
    
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ok = true;
    for(int i = 1; i <= n && ok; i++)
        if(color[i] == -1 && !adj[i].empty())
            ok = solve(i);
    
    if(!ok) cout << -1 << endl;
    else{
        cout << p1.size() << endl;
        for(int u : p1)
            cout << u << " ";
        cout << endl;
        cout << p2.size() << endl;
        for(int u : p2)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
