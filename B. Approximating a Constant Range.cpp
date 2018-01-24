#include <bits/stdc++.h>
using namespace std;

int dp[100005][5];

int main(){
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<int> v;
    
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
        dp[i][0] = dp[i][1] = 1;
    }
    
    int res = 1;
    
    for(int i = 1; i < n; i++){
        if(v[i] == v[i-1]){
            dp[i][0] += dp[i-1][0];
            dp[i][1] += dp[i-1][1];
        }
        else if(v[i] < v[i-1]){
            dp[i][1] += dp[i-1][0];
        }
        else{
            dp[i][0] += dp[i-1][1];
        }
        res = max(res, dp[i][0]);
        res = max(res, dp[i][1]);
    }
    cout << res << endl;
    return 0;
}
