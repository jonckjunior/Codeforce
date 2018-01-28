#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<int> pos, dist, cost;
vector<ii> v;
int dp[100005];

int solve(int n){
    if(dp[n] != -1) return dp[n];
    int p = lower_bound(pos.begin(), pos.end(), pos[n] - dist[n]) - pos.begin();
    int res = (n-p) + solve(p-1);
    return dp[n] = res;
}

int main(){
    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a,b; cin >> a >> b;
        v.push_back(ii(a,b));
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        pos.push_back(v[i].first);
        dist.push_back(v[i].second);
    }
    for(int i = n-1; i >= 0; i--)
        solve(i);
    int res = 1e9;
    for(int i = 0; i < n; i++)
        res = min(res, dp[i] + (n-i-1));
    cout << res << endl;
    return 0;
}
