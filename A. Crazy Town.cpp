#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll x, y; cin >> x >> y;
    ll px, py; cin >> px >> py;
    ll n; cin >> n;
    ll res = 0;
    for(int i = 0; i < n; i++){
        ll a, b, c; cin >> a >> b >> c;
        if(1LL*a*x + b*y + c > 0 != 1LL*a*px + b*py + c > 0)
            res++;
    }
    cout << res << endl;
    return 0;
}
