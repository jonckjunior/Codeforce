#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll color[1005], mod = 1000000007;
ll dp[1005][1005];
ll memo[1005];
ll sum[1005];

int main(){
    
    ll k; cin >> k;
    ll n = 0;
    for(int i = 1; i <= k; i++){
        cin >> color[i];
        sum[i] = sum[i-1] + color[i];
        n += color[i];
    }
    
    for(int i = 0; i <= n; i++)
        dp[i][0] = dp[i][i] = 1;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            dp[i][j] = (dp[i-1][j-1]%mod + dp[i-1][j]%mod)%mod;
    memo[1] = 1;
    for(int i = 2; i <= k; i++)
        memo[i] = (memo[i-1]*dp[sum[i-1] + color[i] - 1][color[i] - 1])%mod;
    cout << memo[k] << endl;
}
