#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int len;
const int REST = 0, GYM = 1, CONTEST = 2;
int dp[105][5];

int solve(int n, int last){
    if(n == len) return 0;
    if(dp[n][last] != -1) return dp[n][last];
    int ans = solve(n+1, REST) + 1;
    if(last == REST){
        if(v[n] == 1 || v[n] == 3)
            ans = min(ans, solve(n+1, CONTEST));
        if(v[n] == 2 || v[n] == 3)
            ans = min(ans, solve(n+1, GYM));
    }
    else if(last == GYM){
        if(v[n] == 1 || v[n] == 3)
            ans = min(ans, solve(n+1, CONTEST));
    }
    else{
        if(v[n] == 2 || v[n] == 3)
            ans = min(ans, solve(n+1, GYM));
    }
    return dp[n][last] = ans;
}

int main(){
    memset(dp, -1, sizeof dp);
    int n; cin >> n;
    len = n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    
    cout << solve(0,REST) << endl;
    return 0;
}
