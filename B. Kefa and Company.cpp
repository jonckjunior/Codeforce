#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> ii;
vector<ii> v;
vector<ll> money, frd;
ll sum[100005];
/*
    4 5
    75 5
    0 100
    150 20
    75 1
*/
int main(){
    ll n, d; cin >> n >> d;
    d--;
    v.push_back(ii(-1,-1));
    for(ll i = 0; i < n; i++){
        ll m, s; cin >> m >> s;
        v.push_back(ii(m,s));
    }
    sort(v.begin(), v.end());
    
    money.push_back(0);
    frd.push_back(0);
    
    for(ll i = 1; i <= n; i++){
        //printf("indice %d = %d %d\n", i, v[i].first, v[i].second);
        money.push_back(v[i].first);
        frd.push_back(v[i].second);
        sum[i] = sum[i-1] + v[i].second;
    }
    //cout << endl;
    ll res = 0;
    for(ll i = 1; i <= n; i++){
        ll aux = upper_bound(money.begin(), money.end(), money[i]+d) - money.begin();
        //printf("do valor %d de money pode ir até o indice %d\n", v[i], aux-1);
        res = max(res, sum[aux-1] - sum[i-1]);
    }
    cout << res << endl;
}
