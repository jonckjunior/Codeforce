#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int dp[4005], v[3], mini;

int solve(int n){
    if(n < mini)
        return (n == 0 ? 0 : -inf);
    if(dp[n] != -1) return dp[n];
    dp[n] = -inf;
    for(int i = 0; i < 3; i++)
        dp[n] = max(dp[n], solve(n-v[i]) + 1);
    return dp[n];
}

int main() {
    memset(dp, -1, sizeof dp);
    int n; cin >> n >> v[0] >> v[1] >> v[2];
    mini = min(v[0], v[1]);
    mini = min(mini, v[2]);
    cout << solve(n) << endl;
}
