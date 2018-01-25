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
    v.push_back(ii(-1,-1));
    for(ll i = 0; i < n; i++){
        ll m, s; cin >> m >> s;
        v.push_back(ii(m,s));
    }
    sort(v.begin(), v.end());
    
    money.push_back(0);
    frd.push_back(0);
    
    for(ll i = 1; i <= n; i++){
        money.push_back(v[i].first);
        frd.push_back(v[i].second);
        sum[i] = sum[i-1] + v[i].second;
    }
    //cout << endl;
    ll esq = 1, dir = 1, res = 0, sum = 0;
    while(dir <= n){
        sum += frd[dir];
        while(abs(money[esq] - money[dir]) >= d){
            sum -= frd[esq++];
        }
        res = max(res, sum);
        dir++;
    }
    cout << res << endl;
}
