#include <bits/stdc++.h>
using namespace std;

/*
    10 3
    1 2 6 2 3 6 9 18 3 9
*/
typedef long long int ll;
typedef vector<ll> vi;

vi v;
map<ll,vi> mapa;
map<ll,vi> soma;
int main(){
    ios::sync_with_stdio(false);
    
    int n,k; cin >> n >> k;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        v.push_back(x);
        mapa[x].push_back(i);
    }
    
    ll res = 0;
    
    for(int i = 0; i < n; i++){
        ll x = v[i];
        if(x%k != 0) continue;
        ll y = x/k, z = x*k;
        ll esq = lower_bound(mapa[y].begin(), mapa[y].end(), i)-mapa[y].begin();
        ll dir = mapa[z].end()-upper_bound(mapa[z].begin(), mapa[z].end(), i);
        res += esq*dir;
    }
    cout << res << endl;
    return 0;
}
