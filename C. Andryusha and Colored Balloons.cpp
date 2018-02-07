#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vector<vi> adj;
int color[200005], n;

void solve(){
    queue<int> q, p;
    q.push(1);
    p.push(0);
    color[1] = 1;
    int numColor = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        int pai = p.front(); p.pop();
        int corzera = 1;
        for(int v : adj[u])
            if(color[v] == 0){
                while(corzera == color[u] || corzera == color[pai]) corzera++;
                color[v] = corzera++;
                q.push(v);
                p.push(u);
            }
        numColor = max(numColor, corzera-1);
    }
    cout << numColor << endl;
    for(int i = 1; i <= n; i++)
        cout << color[i] << " ";
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    
    cin >> n;
    adj.assign(n+5, vi());
    
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    solve();
    return 0;
}
