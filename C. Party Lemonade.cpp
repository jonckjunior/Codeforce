#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll cost[50], mask[50], sum[50];
vector<ll> v;
ll n, l;

/*
    4 3
    10 100 1000 10000
    1   2   4     8
*/

ll solve(int bit){
    if(bit == 0) return cost[bit] = v[bit];
    ll res = solve(bit-1)*2;
    if(bit < n)
        res = min(res, v[bit]);
    return cost[bit] = res;
}

int main() {
    ios::sync_with_stdio(false);
    
    cin >> n >> l;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        v.push_back(x);
    }
    
    solve(32);
    
    for(int i = 32; i >= 0; i--)
        if( (1LL << i) & l ){
            mask[i] = 1;
        }
        
    sum[0] = mask[0] * cost[0];
    for(int i = 1; i <= 32; i++)
        sum[i] = sum[i-1] + mask[i]*cost[i];
    ll res = sum[32];
    
    for(int i = 1; i <= 32; i++)
        if(mask[i] == 0)
            res = min(res, sum[32] - sum[i] + cost[i]);
    cout << res << endl;
    return 0;
}
