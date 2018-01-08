#include <bits/stdc++.h>

using namespace std;

int dp[105][105];

int solve(int a, int b){
    if(a < 0 || b < 0) return -1e9;
    if(a == 0 || b == 0) return 0;
    if(dp[a][b] != -1) return dp[a][b];
     return dp[a][b] = max(solve(a+1,b-2)+1, solve(a-2,b+1)+1);
}

int main() {
    memset(dp, -1, sizeof dp);
    int a,b; cin >> a >> b;
    if(a == 1 && b == 1) cout << 0 << endl;
    else cout << solve(a,b) << endl;
}
