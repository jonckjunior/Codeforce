#include <bits/stdc++.h>
using namespace std;

string s;
int len, dp[5005][5];

int solve(int pos, int n){
    if(pos >= len)
        return 0;
    if(dp[pos][n] != -1) return dp[pos][n];
    int res = 0;
    if(s[pos] == 'a'){
        if(n == 1)
            res = max(res,solve(pos+1, 1) + 1);
        if(n == 2){
            res = max(res,solve(pos+1, 2));
            res = max(res, solve(pos+1, 3) + 1);
        }
        if(n == 3)
            res = max(res,solve(pos+1, 3) + 1);
    }
    else{
        if(n == 1){
            res = max(res, solve(pos+1, 1));
            res = max(res, solve(pos+1, 2) + 1);
        }
        if(n == 2)
            res = max(res, solve(pos+1, 2) + 1);
        if(n == 3)
            res = max(res, solve(pos+1, 3));
    }
    //printf("max de %d %d = %d\n", pos, n, res);
    return dp[pos][n] = res;
}
int main(){
    memset(dp, -1, sizeof dp);
    ios::sync_with_stdio(false);
    cin >> s;
    len = s.size();
    cout << solve(0,1) << endl;
    return 0;
}
