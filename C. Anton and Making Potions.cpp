#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> fst, snd, numsnd, numfst;

int main() {
    
    ll n, m, k; cin >> n >> m >> k;
    ll x, s; cin >> x >> s;
    
    for(ll i = 0; i < m; i++){
        ll x; cin >> x;
        numfst.push_back(x);
    }
    for(ll i = 0; i < m; i++){
        ll x; cin >> x;
        fst.push_back(x);
    }
        
    for(ll i = 0; i < k; i++){
        ll x; cin >> x;
        numsnd.push_back(x);
    }
    for(ll i = 0; i < k; i++){
        ll x; cin >> x;
        snd.push_back(x);
    }
        
    ll res = n * x;

    for(ll i = 0; i < m; i++)
        if(fst[i] <= s)
            res = min(res, numfst[i]*n*1LL);
    for(ll i = 0; i < k; i++)
        if(snd[i] <= s)
            res = min(res, x*(numsnd[i] >= n ? 0LL : n-numsnd[i]) );
    
    for(ll i = 0; i < m; i++){
        if(fst[i] > s) continue;
        ll aux = res;
        ll pos = upper_bound(snd.begin(), snd.end(), s-fst[i])-snd.begin() - 1;
        if(pos >= 0) aux = (n-numsnd[pos])*numfst[i]*1LL;        
        res = min(res, aux);
    }
    cout << res << endl;
    return 0;
}
