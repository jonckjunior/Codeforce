#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<int> v;
vector<string> vs,rvs;

ll dp[100005][5];

ll solve(int pos, int f){
    if(pos+1 == (int)v.size())
        return 0;
    if(dp[pos][f] != -1) return dp[pos][f];
    ll ans = 1e16;
    if(f == 0){
        if(vs[pos] <= vs[pos+1])
            ans = min(ans, solve(pos+1,0));
        if(vs[pos] <= rvs[pos+1])
            ans = min(ans, solve(pos+1,1) + v[pos+1]);
    }
    else{
        if(rvs[pos] <= vs[pos+1])
            ans = min(ans, solve(pos+1,0));
        if(rvs[pos] <= rvs[pos+1])
            ans = min(ans, solve(pos+1,1) + v[pos+1]);
    }
    return dp[pos][f] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        vs.push_back(s);
        reverse(s.begin(), s.end());
        rvs.push_back(s);
    }
    ll ans = min(solve(0,0), solve(0,1) + v[0]);
    if(ans >= 1e16)
        cout << -1 << endl;
    else
        cout << ans << endl;
}
