#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;

vi v, vis, comp, elem, best;
vector<vi> adj;
string ss[305];

void solve(int u){
    vis[u] = 1;
    comp.push_back(u);
    elem.push_back(v[u]);
    for(int v : adj[u])
        if(!vis[v])
            solve(v);
}

int main(){
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    adj.assign(n+5, vi());
    vis.assign(n+5, 0);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    best = v;
    for(int i = 0; i < n; i++)
        cin >> ss[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(ss[i][j] == '1'){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
    for(int i = 0; i < n; i++)
        if(!vis[i]){
            comp.clear();
            elem.clear();
            solve(i);
            sort(elem.begin(), elem.end());
            sort(comp.begin(), comp.end());
            vi aux = best;
            for(int i = 0; i < (int)comp.size(); i++)
                aux[comp[i]] = elem[i];
            if(aux < best) best = aux;
        }
    for(int val : best)
        cout << val << " ";
    cout << endl;
    return 0;
}
