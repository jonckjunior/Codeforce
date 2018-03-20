#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vii> adj;
int red[200005], dist[200005], retTotal;

void solve(int u, int p){
    //printf("%d %d\n", u, p);
    //printf("red[%d] = %d\n", u, red[u]);
    //printf("dist[%d] = %d\n", u, dist[u]);
    for(ii par : adj[u]){
        int v = par.first, w = par.second;
        if(v != p){
            retTotal += w;
            red[v] = red[u] + w;
            dist[v] = dist[u] + 1;
            solve(v, u);
        }
    }
}

int main(){
    int n; cin >> n;
    adj.assign(n+5, vii());

    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(ii(v,0));
        adj[v].push_back(ii(u,1));
    }

    solve(1, -1);
    int res = 1e9;
    for(int i = 1; i <= n; i++){
        // printf("red[%d] = %d\n", i, red[i]);
        // printf("green[%d] = %d\n", i, dist[i]);
        res = min(res, retTotal-red[i] + dist[i]-red[i] );
        // printf("%d como root tem peso %d\n", i, retTotal-red[i] + dist[i]-red[i]);
    }
    cout << res << endl;
    for(int i = 1; i <= n; i++)
        if(retTotal-red[i] + dist[i]-red[i] == res)
            cout << i << " ";
    cout << endl;
    return 0;
}
