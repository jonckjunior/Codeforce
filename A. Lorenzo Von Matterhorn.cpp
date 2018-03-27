#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
map<ll,ll> dp;

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int op; cin >> op;
        if(op == 1){
            ll u, v, w; cin >> u >> v >> w;
            while(u != v){
                while(u < v){
                    dp[v] += w;
                    v /= 2LL;
                }
                while(v < u){
                    dp[u] += w;
                    u /= 2LL;
                }
            }
        }
        else{
            ll u, v; cin >> u >> v;
            ll res = 0;
            while(u != v){
                while(u < v){
                    res += dp[v];
                    v /= 2LL;
                }
                while(v < u){
                    res += dp[u];
                    u /= 2LL;
                }
            }
            cout << res << endl;
        }
    }
    return 0;
}
