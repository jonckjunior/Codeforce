#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> v;

int main(){
    int n; cin >> n;
    ll res = 0;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        res += x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++)
        res += v[i]*(i+1);
    cout << res-v[n-1] << endl;
    return 0;
}
