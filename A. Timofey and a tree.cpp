#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
vector<ii> vii;

int color[100005];
int cnt[100005];

int main(){
    
    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int u,v; cin >> u >> v;
        u--;v--;
        vii.push_back(ii(u,v));
    }
    
    for(int i = 0; i < n; i++)
        cin >> color[i];
    int aux = 0;
    for(int i = 0 ; i < n-1; i++){
        int u = vii[i].first, v = vii[i].second;
        if(color[u] != color[v]){
            aux++;
            cnt[u]++;
            cnt[v]++;
        }
    }
    
    for(int i = 0; i < n; i++)
        if(cnt[i] == aux){
            cout << "YES" << endl;
            cout << i+1 << endl;
            return 0;
        }
    cout << "NO" << endl;
    return 0;
}
