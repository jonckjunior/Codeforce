#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> ii;

int main(){
    cout.sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    map<ll, multiset<ll> > cnt;

    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        cnt[x].insert(i);
    }

    for(auto& par : cnt){
        ll x = par.first;
        multiset<ll>& ms = cnt[x];
        while(ms.size() >= 2){
            ms.erase(ms.begin());
            ll pos = *(ms.begin());
            ms.erase(ms.begin());
            cnt[x*2].insert(pos);
        }
    }

    vector<ii> v;
    for(auto& par : cnt){
        if(par.second.size() > 0)
            v.push_back(ii( *(par.second.begin()), par.first ) );
    }
    stable_sort(v.begin(), v.end());
    cout << v.size() << endl;
    for(ii par : v)
        cout << par.second << " ";
    cout << endl;

    return 0;
}
