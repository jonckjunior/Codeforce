#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;

vector<ii> v;
vector<vi> adj;
int vis[105];

void solve(int u){
    vis[u] = 1;
    for(int v : adj[u])
        if(!vis[v])
            solve(v);
}

int main(){
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    adj.assign(n+5, vi());
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        v.push_back(ii(x,y));
    }
    
    for(int i = 0; i < n; i++){
        int x1 = v[i].first, y1 = v[i].second;
        for(int j = i+1; j < n; j++){
            int x2 = v[j].first, y2 = v[j].second;
            if(x1 == x2 || y1 == y2){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++)
        if(!vis[i]){
            solve(i);
            res++;
        }
    cout << res-1 << endl;
    return 0;
}
