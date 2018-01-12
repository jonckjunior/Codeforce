#include <bits/stdc++.h>

using namespace std;

int n,k,dp[2005][2005], mod = 1000000007;

int solve(int v, int f){
    if(f == k) return 1;
    if(dp[v][f] != -1) return dp[v][f];
    int res = 0;
    for(int i = 1; v*i <= n; i++)
        res = (res%mod + solve(v*i, f+1)%mod)%mod;
    return dp[v][f] = res;
}

int main(){
    memset(dp, -1, sizeof dp);
    cin >> n >> k;
    int res = 0;
    for(int i = 1; i <= n; i++)
        res = (res%mod + solve(i, 1)%mod)%mod;
    cout << res << endl;
}
