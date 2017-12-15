#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main() {
    ll a,b,c; cin >> a >> b >> c;
    ll res = a*((c*(c+1))/2);
    if(b >= res) cout << 0 << endl;
    else cout << abs(res-b) << endl;
    return 0;
}