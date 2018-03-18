#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int n;
string s;
//1213
int bit(int b){return (1 << b);}
int dp[10005][3000], mod = 1e9+7;
int solve(int u, int mask){
    if(u >= n)
        return 1;
    if(dp[u][mask] != -1)
        return dp[u][mask];
    int res = solve(u+1, bit(s[u]-'0'))%mod;
    if (!(mask & (bit(s[u]-'0'))))
        res = (res%mod + solve(u+1, bit(s[u]-'0')|mask)%mod)%mod;
    return dp[u][mask] = res;
}

int main(){
    ios::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    cin >> n >> s;
    cout << solve(0, bit(s[0]-'0')) << endl;
    return 0;
}
