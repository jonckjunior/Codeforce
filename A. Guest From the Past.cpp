#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios::sync_with_stdio(false);
    ll n, a, b, c; cin >> n >> a >> b >> c;
    ll res = 0;
    while(n >= a || n >= b){
        if(n >= a && n >= b){
            if(a <= b-c){
                res += (n/a);
                n -= (n/a) * a;
            }
            else{
                ll dif = b-c;
                ll num = n-b;
                res += 1 + num/dif;
                n = n + (1 + num/dif)*c - (1 + num/dif)*b;
            }
        }
        else if(n >= b){
            ll dif = b-c;
            ll num = n-b;
            res += 1 + num/dif;
            n = n + (1 + num/dif)*c - (1 + num/dif)*b;
        }
        else{
            res += (n/a);
            n -= (n/a) * a;
        }
    }
    cout << res << endl;
    return 0;
}
