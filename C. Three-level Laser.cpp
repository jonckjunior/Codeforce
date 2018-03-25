#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
map<ll, ll> mapa;
vector<ll> v;

/*

    a/b > c/d
    a.d > c.b
*/

ii f(ll i, ll j, ll k){
    return ii(v[k] - v[j], v[k] - v[i]);
}

bool func(ii& a, ii& b){
    return(a.first * b.second  < b.first * a.second);
}
    
int main(){
    ll n, u; cin >> n >> u;
    
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        mapa[x] = i;
        v.push_back(x);
    }
    vector<ii> res;
    for(ll i = 0; i < n-2; i++){
        int pos = upper_bound(v.begin(), v.end(), v[i]+u)-v.begin()-1;
        if(v[pos] <= v[i+1])
            continue;
        ll a = i, b = i+1, c = pos;
        res.push_back(f(a,b,c));
    }
    sort(res.begin(), res.end(), func);
    if(res.empty())
        printf("-1\n");
    else{
        ii ans = res.back();
        printf("%.9f\n", (double)(ans.first) / ans.second);
    }
    return 0;
}
