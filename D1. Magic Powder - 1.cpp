#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios::sync_with_stdio(false);
    
    ll n, k; cin >> n >> k;
    vector<ll> a, b;
    
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.push_back(x);
    }
    
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        b.push_back(x);
    }
    ll esq = 0, dir = 2e9;
    ll res = 0;
    while(esq <= dir){
        ll mid = (esq+dir)/2LL;
        
        ll x = 0;
        for(int i = 0; i < n; i++){
            x += max(0LL, mid*a[i] - b[i]);
            if(x > k)
                x = k+1;
        }
        if(x <= k){
            esq = mid+1;
            res = mid;
        }
        else
            dir = mid-1;
    }
    //cout << "finished" << endl;
    cout << res << endl;
    return 0;
}
