#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

map<string, int> mapa;
vector<vi> adj;
vi vis;

int solve(int u){
    vis[u] = 1;
    int ans = 0;
    for(int v : adj[u])
        ans = max(ans, solve(v)+1);
    return ans;
}

int main(){
    int n; cin >> n;
    adj.assign(n+5, vi());
    vis.assign(n+5, 0);
    int k = 1;
    for(int i = 0; i < n; i++){
        string s1, token, s2; cin >> s1 >> token >> s2;
        for(int i = 0; i < (int)s1.size(); i++)
            s1[i] = toupper(s1[i]);
        for(int i = 0; i < (int)s2.size(); i++)
            s2[i] = toupper(s2[i]);
        int u = mapa[s1];
        int v = mapa[s2];
        if(u == 0) u = mapa[s1] = k++;
        if(v == 0) v = mapa[s2] = k++;
        //printf("%s = %d\n", s1.c_str(), u);
        //printf("%s = %d\n", s2.c_str(), v);
        adj[v].push_back(u);
    }
    cout << solve(mapa["POLYCARP"]) + 1 << endl;
}
