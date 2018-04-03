#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;

ll md = 1e9+7;

ll sumMod(ll a, ll b){
    return (a%md + b%md)%md;
}

ll multMod(ll a, ll b){
    return ((a%md) * (b%md))%md;
}

int main(){

    ll a, b; cin >> a >> b;
    ll res = 0;

    for(ll i = 1; i <= a; i++)
        res = sumMod(res, multMod(((b*(b-1))/2)%md, (i*b+1) ) );
    cout << res << endl;
    return 0;
}
