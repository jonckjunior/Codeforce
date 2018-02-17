#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
vector<vi> adj, comp;

ll cost[100005], dfsCounter;
vi dfs_num, dfs_low, visited, S;


void solve(ll u){
    dfs_num[u] = dfs_low[u] = dfsCounter++;
    S.push_back(u);
    visited[u] = 1;
    for(ll v : adj[u]){
        if(dfs_num[v] == -1)
            solve(v);
        if(visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    
    if(dfs_low[u] == dfs_num[u]){
        //prllf("achou em %d\n", u);
        vi conexo;
        while(1){
            ll v = S.back(); S.pop_back();
            conexo.push_back(cost[v]);
            visited[v] = 0;
            if(u == v) break;
        }
        sort(conexo.begin(), conexo.end());
        comp.push_back(conexo);
    }
    //prllf("low de %d = %d\n", u, dfs_low[u]);
}

int main(){
    
    ll n; cin >> n;
    for(ll i = 1; i <= n; i++)
        cin >> cost[i];
    
    adj.assign(n+5, vi());
    dfs_num.assign(n+5, -1);
    dfs_low.assign(n+5, 0);
    visited.assign(n+5, 0);
    
    
    ll m; cin >> m;
    for(ll i = 0; i < m; i++){
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    
    for(ll i = 1; i <= n; i++)
        if(dfs_num[i] == -1)
            solve(i);
    
    ll mini = 0;
    for(ll i = 0; i < (ll)comp.size(); i++)
        mini += comp[i][0];
    ll way = 1;
    for(ll i = 0; i < (ll)comp.size(); i++){
        ll aux = upper_bound(comp[i].begin(), comp[i].end(), comp[i][0])-comp[i].begin();
        //prllf("componente %d vai até %d com preço = %d\n",i, aux, comp[i][aux]);        
        way = (way*aux*1LL)%1000000007;
    }
    cout << mini << " " << way << endl;
    return 0;
}
