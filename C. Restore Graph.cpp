#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector< deque<int> > vvi;

int n, k;
int v[100005], deg[100005];
vvi adj;

void solve(int ss){
    queue<int> q; q.push(ss);
    vi dist(n+5, -1);
    vii res;
    dist[ss] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        int d = dist[u];
        for(int cnt = (u == ss ? 0 : 1); cnt < k; cnt++){
            if(!adj[d+1].empty()){
                int viz = adj[d+1].front(); adj[d+1].pop_front();
                dist[viz] = dist[u] + 1;
                q.push(viz);
                res.push_back(ii(u, viz));
            }
            else
                break;
        }
    }

    for(int i = 0; i < n; i++)
        if(dist[i] == -1){
            cout << -1 << endl;
            return;
        }
    cout << res.size() << endl;
    for(ii par : res)
        cout << par.first+1 << " " << par.second+1 << endl;
}

int main(){
    cin >> n >> k;
    adj.assign(n+5, deque<int>());

    for(int i = 0; i < n; i++){
        cin >> v[i];
        adj[v[i]].push_back(i);
        deg[v[i]]++;
    }
    bool flag = true;
    for(int i = 0; i < n; i++)
        if(deg[i+1] > 0 && deg[i] == 0 || deg[0] != 1 || 1LL*deg[i+1] > 1LL*deg[i]*k)
            flag = false;
    if(flag){
        solve(adj[0].front());
    }
    else
        cout << -1 << endl;
    return 0;
}
