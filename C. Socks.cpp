#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
const int maxn = 2e5 + 5;

int c[maxn], p[maxn];
vector<int> adj[maxn];

int pai(int u){return p[u] = (p[u] == u ? u : pai(p[u]));}

void unionFind(int x, int y){
    x = pai(x), y = pai(y);
    p[y] = x;
}

int main(){
    cout.sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, k; cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        p[i] = i;
        cin >> c[i];
    }
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        if(pai(u) != pai(v))
            unionFind(u, v);
    }

    for(int i = 1; i <= n; i++)
        adj[ pai(i) ].push_back(c[i]);
    
    int res = 0;
    for(int i = 1; i <= n; i++){
        map<int,int> cnt;
        for(int cor : adj[i])
            cnt[cor]++;
        
        int sum = 0, best = 0;
        for(ii par : cnt){
            sum += par.second;
            best = max(best, par.second);
        }
        res += (sum-best);
    }
    cout << res << endl;
    return 0;
}
