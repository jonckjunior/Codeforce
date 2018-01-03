#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;


ll v[100005], dp[100005];

ll solve(ll n){
    if(n <= 1) return v[n];
    if(dp[n] != -1) return dp[n];
    return dp[n] = max(solve(n-1), solve(n-2) + v[n]*n);
}

int main(){
    memset(dp, -1, sizeof dp);
    ll n; cin >> n;
    ll maxi = 0;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        maxi = max(maxi, x);
        v[x]++;
    }
    cout << solve(maxi) << endl;
    return 0;
}
