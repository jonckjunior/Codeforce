#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi adj;
int dp[100005];

void solve(int u, int cnt){
    dp[cnt]++;
    for(int v : adj[u])
        solve(v, cnt+1);
}

int main(){
    int n; cin >> n;
    adj.assign(n+5, vi());
    
    for(int i = 2; i <= n; i++){
        int x; cin >> x;
        adj[x].push_back(i);
    }
    solve(1,1);
    int res = 0;
    for(int i = 1; i <= n; i++)
        res += (dp[i]%2);
    cout << res << endl;
    return 0;
}
