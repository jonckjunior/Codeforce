#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int cat[200005], vis[200005], n, m;
vector<vi> adj;

int solve(int u, int c){
    //printf("%d %d\n", u, c);
    if(c > m) return 0;
    if((int)adj[u].size() == 1 && u != 1){
        //printf("%d %d retornando %d\n", u, c, (c <= m));
        return (c <= m);
    }
    vis[u] = 1;
    int res = 0;
    for(int v : adj[u]){
        if(!vis[v])
            res += solve(v, (cat[v] == 1 ? c + 1 : 0 ) );
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    adj.assign(n+5, vi());
    for(int i = 1; i <= n; i++)
        cin >> cat[i];
    for(int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout << solve(1, cat[1]) << endl;
    return 0;
}
