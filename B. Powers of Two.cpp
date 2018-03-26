#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;

map<ll, vi> mapa;

int main(){
    ll n; cin >> n;
    vi v;
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        v.push_back(x);
        mapa[x].push_back(i);
    }
    ll res = 0;
    for(ll i = 0; i < n; i++){
        ll x = v[i];
        for(ll L = log2(x)+1; L <= 32; L++){
            ll aux = floor(pow(2, L)) - x;
            if(mapa.count(aux) > 0){
                res += mapa[aux].end() - upper_bound(mapa[aux].begin(), mapa[aux].end(), i);
            }
        }
    }
    cout << res << endl;
    return 0;
}
