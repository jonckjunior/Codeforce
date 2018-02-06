#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vector<vi> adj;
vi vis;
int esq, dir;

void solve(int u, int side){
    vis[u] = 1;
    if(side == 0) esq++;
    else          dir++;
    for(int v : adj[u])
        if(!vis[v])
            solve(v, !side);
}

int main(){
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    adj.assign(n+5, vi());
    vis.assign(n+5, 0);
    int edge = 0;
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i = 1; i <= n; i++)
        if(!vis[i])
            solve(i, 0);
    //printf("esq = %d\n", esq);
    //printf("dir = %d\n", dir);
    //printf("edge = %d\n", edge);
    cout << 1LL*esq*dir - n + 1 << endl;
    return 0;
}
