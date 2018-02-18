#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;

vector<vi> adj;

int mat[3005][3005];

int main(){
    
    int n, m; cin >> n >> m;
    if(m == 0){
        cout << 0 << endl;
        return 0;
    }
    adj.assign(n+5, vi());
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        mat[u][v] = 1;
        adj[u].push_back(v);
    }
    for(int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());
  /*
    for(int i = 1; i <= n; i++)
        for(int j = i+1; j <= n; j++){
            vi inter;
            set_intersection(adj[i].begin(), adj[i].end(), adj[j].begin(), adj[j].end(), back_inserter(inter));
            mapa_inter[ii(i,j)] = mapa_inter[ii(j,i)] = inter;
        }*/
    
    int res = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            int t = 0;
            for(int viz : adj[i])
                if(mat[viz][j])
                    t++;
            res += (t*(t-1))/2;
        }
    }
    cout << res << endl;
    return 0;
}
