#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> v,v1,v2;

int main() {
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        v.push_back(x);
    }
    
    for(ll i = 0; i < n-1; i++)
        v1.push_back( abs(v[i]-v[i+1]) * (i%2 == 0 ? 1 : -1) );
    for(ll i = 0; i < n-1; i++)
        v2.push_back( abs(v[i]-v[i+1]) * (i%2 == 0 ? -1 : 1) );
    
    ll resmax=0, reslocal=0;
    
    for(ll i = 0; i < (ll)v1.size(); i++){
        reslocal += v1[i];
        if(reslocal <= 0) reslocal = 0;
        resmax = max(resmax, reslocal);
    }
    reslocal = 0;
    for(ll i = 0; i < (ll)v2.size(); i++){
        reslocal += v2[i];
        if(reslocal <= 0) reslocal = 0;
        resmax = max(resmax, reslocal);
    }
    
    cout << resmax << endl;
}
