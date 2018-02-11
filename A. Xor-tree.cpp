#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vector<vi> adj;
int init[100005], vis[100005], goal[100005];
vi vec_res;

int solve(int u, int impar, int par, int len){
    vis[u] = 1;
    if(len%2 == 0 && par%2 == 1) init[u] = !init[u];
    if(len%2 == 1 && impar%2 == 1) init[u] = !init[u];
    int flip = 0;
    if(init[u] != goal[u]){
        flip = 1;
        vec_res.push_back(u);
    }
    int res = flip;
    for(int v : adj[u])
        if(!vis[v]){
            if(flip == 0)
                res += solve(v, impar, par, len+1);
            else
                res += solve(v, impar + (len%2==1), par + (len%2==0), len+1);
        }
    return res;
}

int main(){
    int n; cin >> n;
    adj.assign(n+5, vi());
    
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i = 1; i <= n; i++)
        cin >> init[i];

    for(int i = 1; i <= n; i++)
        cin >> goal[i];
    
    cout << solve(1, 0, 0, 1) << endl;
    for(int u : vec_res)
        cout << u << endl;
    
    return 0;
}
