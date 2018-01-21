#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll sum[5005], n, m, k, dp[5005][5005];

ll solve(int u, int k){
    if(k == 0) return 0;
    if(u >= n) return -1e15;
    if(dp[u][k] != -1) return dp[u][k];
    ll res = 0;
    res = max(solve(u+1,k), solve(u+m, k-1) + sum[u]);
    return dp[u][k] = res;
}

int main(){
    memset(dp, -1, sizeof dp);
    cin >> n >> m >> k;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    for(int i = 0; i < n; i++)
        for(int j = i; j < i+m && j < n; j++){
            sum[i] += v[j];
        }
    cout << solve(0,k) << endl;
}
