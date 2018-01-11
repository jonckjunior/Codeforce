#include <bits/stdc++.h>

using namespace std;
int mod = 1000000007;
int n,k,d;
int dp[105][5];

int solve(int s, int f){
    if(s >= n)
        return (s == n && f == 1);
    if(dp[s][f] != -1) return dp[s][f];
    int res = 0;
    for(int i = 1; i <= k; i++)
        res = (res%mod + solve(s+i, f || (i >= d))%mod ) %mod;
    return dp[s][f] = res;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> n >> k >> d;
    int res = 0;
    for(int i = 1; i <= k; i++)
        res = (res%mod + solve(i, (i >= d))%mod)%mod;
    cout << res << endl;
}
