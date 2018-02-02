#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll bit(ll b){return (1LL << b);}

ll mt[20][20], n, m, k, dp[18][(1<<18)];
ll v[20];

ll solve(ll pos, ll bitmask, ll nodos){
    if(nodos == m) return 0;
    if(dp[pos][bitmask] != -1) return dp[pos][bitmask];
    ll res = 0;
    for(ll i = 0; i < n; i++)
        if(!(bit(i)&bitmask))
            res = max(res, solve(i, bitmask|bit(i), nodos+1) + mt[pos][i] + v[i]);
    return dp[pos][bitmask] = res;
}

int main(){
    ios::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    cin >> n >> m >> k;
    ll sum = 0;
    for(ll i = 0; i < n; i++)
        cin >> v[i];
    
    for(ll i = 0; i < k; i++){
        ll x, y, c; cin >> x >> y >> c;
        x--;y--;
        mt[x][y] = c;
    }
    
    ll res = 0;
    for(ll i = 0; i < n; i++)
        res = max(res, solve(i, bit(i), 1) + v[i]);
    cout << res << endl;
    return 0;
}
