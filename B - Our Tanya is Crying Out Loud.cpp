#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
int main(){
    ll n, k, a, b; cin >> n >> k >> a >> b;
    if(k == 1)
        k = 2e9+7;
    ll res = 0;
    while(n > 1){
        if(n < k){
            res += (n-1)*a;
            n = 1;
        }
        else if(n%k == 0){
            res += min(b, (n-n/k)*a);
            n /= k;
        }
        else{
            res += (n%k)*a;
            n -= n%k;
        }
    }
    cout << res << endl;
    return 0;
}
