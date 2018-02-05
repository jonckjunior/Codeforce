#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<vi> adj;

int vis[505];

void solve(int u){
    vis[u] = 1;
    for(int v : adj[u])
        if(!vis[v])
            solve(v);
}

int main(){
    ios::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    adj.assign(n+m+5, vi());
    
    int res = 0, found = 1;
    
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        if(k != 0) found = 0;
        for(int j = 0; j < k; j++){
            int x; cin >> x;
            adj[i].push_back(n+x);
            adj[n+x].push_back(i);
        }
    }

    if(found) cout << n << endl;
    else{
        for(int i = 0; i < n; i++)
            if(!vis[i]){
                res++;
                solve(i);
            }
        cout << res-1 << endl;
    }
    return 0;
}
