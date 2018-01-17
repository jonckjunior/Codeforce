#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vector<vi> adj;
vi pai;

int solve(int u){
    int ans = 0;
    for(int v : adj[u])
        ans = max(ans, solve(v) + 1);
    return ans;
}

int main(){
    int n; cin >> n;
    adj.assign(n+5, vi());
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x == -1){
            pai.push_back(i);
        }
        else{
            x--;
            adj[x].push_back(i);
        }
    }
    int ans = 0;
    for(int i = 0; i < (int)pai.size(); i++)
        ans = max(ans, solve(pai[i]) + 1);
    cout << ans << endl;
}
