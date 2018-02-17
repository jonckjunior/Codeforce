#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vi v, orig, vis;

map<int,int> mapa;



int main(){
    
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        mapa[x] = i;
        v.push_back(x);
        orig.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    for(int i = 0; i < n; i++){
        int x = v[i];
        int pos = mapa[x];
        orig[pos] = i;
    }
    
    vis.assign(n+5, 0);
    vector<vi> res;
    
    for(int i = 0; i < n; i++)
        if(!vis[i]){
            vi comp;
            int u = i;
            while(!vis[u]){
                vis[u] = 1;
                comp.push_back(u);
                u = orig[u];
            }
            res.push_back(comp);
        }
    cout << res.size() << endl;
    for(vi& comp : res){
        cout << comp.size() << " ";
        for(int x : comp)
            cout << x+1 << " ";
        cout << endl;
    }
    
    return 0;
}
