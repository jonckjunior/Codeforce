#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi adj;
vi vis, ciclo, S;
bool flag;

void solve(int u, int p){
    S.push_back(u);
    vis[u] = 1;
    for(int v : adj[u])
        if(v != p){
            if(!vis[v])
                solve(v, u);
            else if(!flag){
                flag = true;
                for(int i = (int)S.size() - 1;  ; i--){
                    ciclo.push_back(S[i]);
                    if(S[i] == v)
                        break;
                }
            }
        }
    S.pop_back();
}

int main(){
    int n; cin >> n;
    adj.assign(n+5, vi());
    vis.assign(n+5, 0);

    for(int i = 0; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    flag = false;
    solve(1, -1);

    vis.assign(n+5, -1);
    queue<int> q;
    for(int weiss : ciclo){
        vis[weiss] = 0;
        q.push(weiss);
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : adj[u]){
            if(vis[v] == -1){
                vis[v] = vis[u] + 1;
                q.push(v);
            }
        }
    }
    for(int i = 1; i <= n; i++)
        cout << vis[i] << " ";
    cout << endl;
    return 0;
}
