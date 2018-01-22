#include <bits/stdc++.h>
using namespace std;

int v1,v2,t,d;
int dp[1005][1005];

int solve(int sec, int vel){
    if( (vel <= 0) || abs(v2-vel) > (t-sec)*d) return -1e9;
    if(sec == t)
        return (vel == v2 ? 0 : -1e9);
    if(dp[sec][vel] != -1) return dp[sec][vel];
    int res = 0;
    for(int i = 0; i <= d; i++){
        res = max(res, solve(sec+1, vel+i) + i+vel);
        res = max(res, solve(sec+1, vel-i) + vel-i);
    }
    return dp[sec][vel] = res;
}

int main(){
    memset(dp, -1, sizeof dp);
    cin >> v1 >> v2;
    cin >> t >> d;
    cout << solve(1, v1) + v1 << endl;
    return 0;
}
